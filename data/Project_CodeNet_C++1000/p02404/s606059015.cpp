#include<iostream>
using namespace std;

int main() {
	for (;;) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		for (int k = 0; k < b; k++) {
			cout << "#";
		}
		for (int m = 0; m < a - 2; m++) {
			cout << endl;
			cout << "#";
			for (int j = 0; j < b - 2; j++) {
				cout << ".";
			}
			cout << "#";
		}
			cout << endl;
		for (int l = 0; l < b; l++) {
			cout << "#";
		}
		cout << endl;
		cout << endl;
	}
}
