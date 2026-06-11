#include<iostream>
using namespace std;
int main() {
	int tate, yoko;
	cin >> tate >> yoko;
	while (tate != 0 || yoko != 0) {
		for (int i = 0; i < tate; i++) {
			for (int j = 0; j < yoko; j++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
		cin >> tate >> yoko;
	}
	return 0;
}