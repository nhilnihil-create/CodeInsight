#include <iostream>
using namespace std;

int main()
{
	for (;;) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		else {
			for (int i = 0; i < a / 2; i++) {
				for (int i = 0; i < b / 2; i++) {
					cout << "#.";
				}
				if (b % 2 == 1) {
					cout << "#";
				}
				cout << endl;
				for (int j = 0; j < b / 2; j++) {
					cout << ".#";
				}
				if (b % 2 == 1) {
					cout << ".";
				}
				cout << endl;
			}
			if (a % 2 == 0) {
				cout << endl;
			}
			if (a % 2 == 1) {
				for (int k = 0; k < b / 2; k++) {
					cout << "#.";
				}
				if (b % 2 == 1) {
					cout << "#";
				}
				cout << endl;
				cout << endl;
			}
		}
	}
}
