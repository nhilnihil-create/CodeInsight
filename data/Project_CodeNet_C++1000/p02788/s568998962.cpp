#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, d, a, ans = 0;
	cin >> n >> d >> a;
	d *= 2;
	vector<pair<ll, ll>> xh(n);
	rep(i,n) cin >> xh[i].first >> xh[i].second;
	sort(xh.begin(), xh.end());
	queue<pair<ll, ll>> q;
	ll totdm = 0;
	rep(i,n) {
		ll x = xh[i].first;
		ll h = xh[i].second;
		while (!q.empty() && q.front().first < x) {
			totdm -= q.front().second;
			q.pop();
		}
		h -= totdm;
		if (h > 0) {
			ll count = (h + a - 1) / a;
			ans += count;
			totdm += count * a;
			q.emplace(x + d, count * a);
		}

	}
	cout << ans << endl;
	return 0;
}
