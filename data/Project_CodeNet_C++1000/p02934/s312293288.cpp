#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	long double a;
	long double ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		ans += (1.0 / a);
	}
	cout << fixed << setprecision(12) << 1 / ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
