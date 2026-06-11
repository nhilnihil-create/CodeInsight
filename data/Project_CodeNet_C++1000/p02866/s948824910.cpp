#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> d(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		if (i == 1 && d[i] != 0) {
			cout << 0; exit(0);
		}
		if (i != 1 && d[i] == 0) {
			cout << 0; exit(0);
		}
	}

    vector<int> cnt(n+1);
    for (int i = 1; i <= n; i++) {
		cnt[d[i]]++;
    }
    long long ans = 1;
    int mx = *max_element(d.begin(), d.end());
    for (int i = 1; i <= mx; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			ans *= cnt[i-1];
			ans %= M;
		}
    }
    cout << ans;

	return 0;
}
