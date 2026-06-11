#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x >= 2000) {
		cout << 1 << endl;
		return 0;
	}
	int hun = x / 100;
	int min = hun * 100;
	int max = min + 5 * hun;
	if (min <= x && x <= max) cout << 1 << endl;
	else cout << 0 << endl;
}