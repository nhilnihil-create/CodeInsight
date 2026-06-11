#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

signed main () {
	int n, k;
	cin >> n >> k;
	vector < int > a(n + 1, 0), pref(n + 1, 0), p(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = (pref[i - 1] + a[i]) % k;
		p[i] = (pref[i] - i + ((inf / k) * k)) % k;
	}
	map < int, int > cnt;
	int64_t ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (i >= k)
			--cnt[p[i - k]];
		ans += cnt[p[i]];
		++cnt[p[i]];
	}
	cout << ans << '\n';
}
