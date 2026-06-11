#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	int result = 0;
	if (X == 2) {
		cout << 2 << endl;
		exit(0);
	}
	while (result == 0) {
		for (int i = 2; i < X; i++) {
			if (X % i == 0) {
				break;
			}
			else if (X % i != 0 && i + 1 == X) {
				result = X;
			}
		}
		X++;
	}
	cout << result << endl;
}