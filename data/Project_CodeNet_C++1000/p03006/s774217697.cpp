#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;//10^18
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll ok[123456];
signed main() {
	ll n = 0, k = 0, cnt = 1, sum = 1, ans = 0;
	cin >> n; vector<ll> t(n), u(n); map<ll, map<ll, ll>> m;
	for (int h = 0; h < n; h++) { cin >> t[h] >> u[h]; }
	for (int h = 0; h < n; h++) {
		for (int i = h + 1; i < n; i++) {
			ll a = t[h] - t[i], b = u[h] - u[i];
			m[a][b]++; m[0 - a][0 - b]++;
			ans = max(ans, max(m[a][b], m[0 - a][0 - b]));
		}
	}
	cout << n - ans << endl;
	return 0;
}