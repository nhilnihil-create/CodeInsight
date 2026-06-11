#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	int cnt = 1, ans = 0;
	while (cnt < b) {
		ans++;
		cnt += a - 1;
	}
	cout << ans;
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
