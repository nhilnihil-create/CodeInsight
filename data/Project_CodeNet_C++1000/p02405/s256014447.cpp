#include<iostream>
using namespace std;
int main() {
	int tate, yoko;
	cin >> tate >> yoko;
	while (tate != 0 || yoko != 0) {
		for (int i = 0; i < tate; i++) {
			for (int j = 0; j < yoko; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
				else {
					if (j % 2 == 0) {
						cout << ".";
					}
					else {
						cout << "#";
					}
				}
			}
			cout << endl;
		}
		cout << endl;
		cin >> tate >> yoko;
	}
	return 0;
}