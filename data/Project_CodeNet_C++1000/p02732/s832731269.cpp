#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	rep(i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<pll> v(n + 1);
	for (auto p : mp) {
		ll t = p.first;
		ll u = p.second;
		v[t].first = u * (u - 1) / 2;
		v[t].second = (u - 1) * (u - 2) / 2;
	}
	ll s = 0;
	rep(i, n + 1) s += v[i].first;
	rep(i, n) {
		ll ans = s - v[a[i]].first + v[a[i]].second;
		cout << ans << endl;
	}
	return 0;
}