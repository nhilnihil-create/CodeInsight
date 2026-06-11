#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (a > 9 || b > 9) {
		cout << -1 << '\n';
		return 0;
	}
	cout << a * b << '\n';
	return 0;
}
