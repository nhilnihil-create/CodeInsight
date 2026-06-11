#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	for (int i = 1; i < 9; i++) {
		if (200 * i + 200<= X && X < 200 * i + 400) {
			cout << 9 - i << endl;
			break;
		}
	}
}
