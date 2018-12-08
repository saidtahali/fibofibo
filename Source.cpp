#include<iostream>
#define length 1000

using namespace std;
void walkThrow(int  a[length], int  b[length]);
void logArray(int a[]);
int main() {
	int a[length], b[length], carry = 0;
	for (int i = 0; i < length; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	b [0] = 1;
	int x = 1;
	while (1) {
		walkThrow(a, b);
		x++;
		if (a[length-1] > 0) {
			logArray(a);
			break;
		}
		walkThrow(b, a);
		x++;
		if (b[length-1] > 0) {
			logArray(b);
			break;
		}
	}
	cout << "F" << x;
	return 0;
}
void walkThrow(int  a[length], int  b[length]) {
	int carry = 0;
	for (int i = 0; i < length; i++) {
		int val = a[i] + b[i] + carry;
		if (val >= 10) {
			carry = 1;
			val -= 10;
		}
		else {
			carry = 0;
		}
		a[i] = val;
	}
}
void logArray(int a[]) {
	for (int i = length-1; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;
}
