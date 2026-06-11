#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T1, typename T2>
istream& operator>>(istream& os, pair<T1, T2>& p) {
	os >> p.first >> p.second;
	return os;
}

int main() {
	ll n, d, a;
	cin >> n >> d >> a;
	vector<pair<ll, ll>> v(n);
	for (ll i = 0; i < n; ++i)cin >> v[i];
	sort(v.begin(), v.end());
	vector<ll> x(n);
	vector<ll> h(n);
	for (ll i = 0; i < n; ++i) {
		x[i] = v[i].first;
		h[i] = (v[i].second - 1) / a + 1;
	}
	vector<ll> sum(n, 0);
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		if (i != 0)sum[i] += sum[i - 1];
		ll preans = max(0ll,h[i] - sum[i]);
		ans += preans;
		sum[i] += preans;
		ll idx = distance(x.begin(), upper_bound(x.begin(), x.end(), x[i] + 2 * d));
		if (idx < n)sum[idx] -= preans;
	}
	cout << ans << endl;
}
