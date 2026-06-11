#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	if (!k) {
		cout << "0\n";
		return 0;
	}

	map<int, int> cnt;
	cnt[1] = 1;

	ll ans = 0;

	vector<ll> p(n + 1, 0);

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		p[i + 1] = (p[i] + x) % k;

		if (i >= k - 1) {
			cnt[p[i - k + 1] - i + k]--;
		}

		ans += cnt[k + p[i + 1] - i] + cnt[p[i + 1] - i];

		cnt[p[i + 1] - i]++;
	}

	cout << ans;
}