#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, d, a;
	cin >> n >> d >> a;
	d = 2 * d;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	sort(all(p));
	ll ans = 0;
	ll tot = 0;
	queue<pair<ll, ll>> que;
	rep(i, n) {
		ll x = p[i].first;
		ll h = p[i].second;
		while (que.size() && que.front().second < x) {
			tot -= que.front().first;
			que.pop();
		}
		h -= tot;
		if (h > 0) {
			ll num = (h + a - 1) / a;
			ans += num;
			ll damage = num * a;
			tot += damage;
			que.emplace(damage, x + d);
		}
	}
	cout << ans << endl;
	return 0;
}
