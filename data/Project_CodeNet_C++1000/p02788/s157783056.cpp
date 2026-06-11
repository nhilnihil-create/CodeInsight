#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll d, a;
	cin >> d >> a;
	pair<ll, ll> p[n];
	rep(i, n) cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	vector<ll> x(n), cnt(n + 1);
	rep(i, n) x[i] = p[i].first;
	ll ans = 0;
	rep(i, n) {
		cnt[i + 1] += cnt[i];
		p[i].second -= a * cnt[i + 1];
		if (p[i].second > 0) {
			ll now = (p[i].second + a - 1) / a;
			ans += now;
			cnt[i + 1] += now;
			int it = upper_bound(all(x), p[i].first + d * 2) - x.begin();
			if (it == n + 1)
				continue;
			else
				cnt[it + 1] -= now;
		}
	}
	cout << ans << endl;
	return 0;
}