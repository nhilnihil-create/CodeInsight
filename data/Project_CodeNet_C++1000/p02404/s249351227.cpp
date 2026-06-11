#include<iostream>
using namespace std;
int main() {
	int tate, yoko;
	cin >> tate >> yoko;
	while (tate != 0 || yoko != 0) {
		for (int i = 0; i < yoko; i++)cout << "#";
		cout << endl;
		for (int i = 1; i < tate-1; i++) {
			for (int j = 0; j < yoko; j++) {
				if (j == 0||j==yoko-1)cout << "#";
				else cout << '.';
			}
			cout << endl;
		}
		for (int i = 0; i < yoko; i++)cout << "#";
		cout << endl;
		cout << endl;
		cin >> tate >> yoko;
	}
	return 0;
}