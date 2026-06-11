#include<iostream>

using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	int code = (4 - X) * 100000;
	int zissou = (4 - Y) * 100000;

	if (X > 3) {
		code = 0;
	}
	if (Y > 3) {
		zissou = 0;
	}

	if (X == 1 && Y == 1) {
		cout << code + zissou + 400000 << endl;
	}
	else {
		cout << code + zissou << endl;
	}

}

