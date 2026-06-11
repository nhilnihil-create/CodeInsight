#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, q;
vector<ll> v;

bool inc(ll i = n - 1) {
	bool flag = true;
	if (v[i] == m) {
		if (i == 0)return false;
		flag = inc(i - 1);
		v[i] = v[i - 1];
	}
	else {
		++v[i];
	}
	return flag;
}

int main() {
	cin >> n >> m >> q;
	v.resize(n, 1);
	v.back() = 0;
	vector<ll> a(q);
	vector<ll> b(q);
	vector<ll> c(q);
	vector<ll> d(q);
	for (ll i = 0; i < q; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (ll i = 0; i < q; ++i) {
		--a[i];
		--b[i];
	}
	ll ans = 0;
	while (inc()) {
		ll preans = 0;
		for (ll i = 0; i < q; ++i) {
			if (v[b[i]] - v[a[i]] == c[i])preans += d[i];
		}
		ans = max(ans, preans);
	}
	cout << ans << endl;
}
