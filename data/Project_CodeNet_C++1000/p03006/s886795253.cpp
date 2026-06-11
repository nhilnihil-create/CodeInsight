#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

signed main() {
	ll n = 0, k = 0, cnt = 1, sum = 1, ans = 0;
	cin >> n; vector<ll>t(n), u(n); map<ll, map<ll, ll>> m;
	rep(h, n) { cin >> t[h] >> u[h]; }
	rep(h, n) {
		for (int i = h + 1; i < n; i++) {
			ll a = t[h] - t[i], b = u[h] - u[i];
			m[a][b]++; m[0 - a][0 - b]++;
			ans = max(ans, max(m[a][b], m[0 - a][0 - b]));
		}
	}
	cout << n - ans << endl;
	return 0;
}