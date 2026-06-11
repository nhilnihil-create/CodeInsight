#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	const long long inf = 1e17 + 1e8;
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i <= n; i++) cin >> a[i];
	long long ans = 0;
	if (n == 0) {
		if (a[0] == 1) ans = 1;
		else ans = -1;
	} else {
		if (a[0] == 0) {
			vector<long long> mx(n + 1, 0);
			mx[0] = 1;
			for (int i = 1; i <= n; i++) {
				mx[i] = mx[i - 1] * 2 - a[i];
				if (mx[i] >= inf) mx[i] = inf;
				if (mx[i] < 0) {
					ans = -1;
				}
				if (i < n && mx[i] == 0) ans = -1;
			}
			if (ans >= 0) {
				long long ver = 0;
				for (int i = n; i > 0; i--) {
					ver += a[i];
					ans += ver;
					if (mx[i - 1] * 2 < ver) {
						ans = -1;
						break;
					}
					ver = min(ver, mx[i - 1]);
				}
				if (ans >= 0) ans++;
			}
		} else {
			ans = -1;
		}
	}
	cout << ans << endl;
	return 0;
}
