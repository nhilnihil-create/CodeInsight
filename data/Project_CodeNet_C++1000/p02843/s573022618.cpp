#include "bits/stdc++.h"

using namespace std;
int main() {
	int X;
	cin >> X;
	for (int i = 1; i <= 1000000; ++i) {
		int min = i * 100;
		int max = i * 105;
		if ((min <= X) && (max >= X)) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
