#include<iostream>
using namespace std;

int main() {

	int X, Y;
	cin >> X >> Y;

	for (int turu = 0; turu < X + 1; turu++) {
		int kame = X - turu;
		if (2 * turu + 4 * kame == Y) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}