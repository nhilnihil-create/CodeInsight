#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, v, w, t; cin >> a >> v >> b >> w >> t;
	int c = abs(a - b);
	if (a == b) {
		cout << "YES" << endl;
		return 0;
	}
	if (w > v) {
		cout << "NO" << endl;
		return 0;
	}
	if (c <= (long long)t * (v - w)) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}

