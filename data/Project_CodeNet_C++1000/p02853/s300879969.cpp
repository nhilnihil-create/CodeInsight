#include"bits/stdc++.h"
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	if (X == 1 && Y == 1) {
		cout << 1000000 << endl;
	}
	else {
		cout << (max(4 - X, 0) + max(4 - Y, 0)) * 100000 << endl;
	}
	return 0;
}