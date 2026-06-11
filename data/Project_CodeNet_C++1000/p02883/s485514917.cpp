#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;//10^18
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll ok[123456];
signed main() {
	ll n = 0, k, b = 0, cnt = 0, ans = 0; cin >> n >> k;
	vector<ll> a(n), v(n);
	for (int h = 0; h < n; h++) { cin >> a[h]; cnt += a[h]; }
	sort(a.begin(), a.end());
	for (int h = 0; h < n; h++) { cin >> v[h]; }
	cnt -= k; ll ng = -1, ok = INF + 1, mid = (ok + ng) / 2;
	while (ok - ng > 1) {
		ll sum = 0, bo = k; vector<ll> ve;
		for (int h = 0; h < n; h++) {
			sum += mid / v[h]; ve.push_back(mid / v[h]);
		}
		sort(ve.begin(), ve.end());
		for (int h = 0; h < n; h++) {
			if (ve[h] < a[h]) { bo -= a[h] - ve[h]; }
		}
		if (bo >= 0 && sum >= cnt) { ok = mid; }
		else { ng = mid; }
		mid = (ok + ng) / 2;
	}
	cout << ok << endl;
	return 0;
}