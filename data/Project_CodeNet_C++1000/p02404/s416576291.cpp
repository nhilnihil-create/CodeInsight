# include<iostream>

using namespace std;
int main() {
	int a, b = 0;
	while (1) {
		cin >> b >> a;
		if (a == 0 && b == 0) {
			break;
		}
		for (int it = 0; it < a; it++) {
			cout << "#";
		}
		cout << endl;
		for (int i = 1; i < b - 1; i++) {
			cout << "#";
			for (int it = 1; it < a - 1; it++) {
				cout << ".";
			}
			cout << "#";
			cout << endl;
		}
		for (int it = 0; it < a; it++) {
			cout << "#";
		}
		cout << endl << endl;
	}
	return 0;
}