#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	ll a[n + 1];
	a[0] = 0;
	rep(i, n) {
		cin >> a[i + 1];
		a[i + 1] += a[i];
	}
	rep(i, n + 1) a[i] = (a[i] - i) % k;
	map<int, int> mp;
	int l = 0, r = 0;
	mp[0]++;
	ll ans = 0;
	while (r != n + 1) {
		if (r - l < k - 1) {
			if (mp[a[++r]]) ans += mp[a[r]];
			mp[a[r]]++;
		} else {
			mp[a[l++]]--;
			if (mp[a[++r]]) ans += mp[a[r]];
			mp[a[r]]++;
		}
	}
	cout << ans << endl;
	return 0;
}