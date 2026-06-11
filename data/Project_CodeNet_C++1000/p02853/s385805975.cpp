#include<iostream>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	int n=0;

	switch (X) {
	case 1:
		n = n + 300000;
		break;
	case 2:
		n = n + 200000;
		break;
	case 3:
		n = n + 100000;
		break;
	default:
		break;
	}
	switch (Y) {
	case 1:
		n = n + 300000;
		break;
	case 2:
		n = n + 200000;
		break;
	case 3:
		n = n + 100000;
		break;
	default:
		break;
	}
	if (n == 600000) {
		n = 1000000;
	}
	cout << n << '\n';

	return 0;
}