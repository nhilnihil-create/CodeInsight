#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<vector<pair<ll, ll>>> v;
	vector<ll> a;
	for (ll i = 0; i < n; ++i) {
		vector<pair<ll, ll>> vv;
		ll ai;
		cin >> ai;
		a.push_back(ai);
		for (ll j = 0; j < ai; ++j) {
			pair<ll, ll> p;
			cin >> p.first >> p.second;
			--p.first;
			vv.push_back(p);
		}
		v.push_back(vv);
	}
	ll ans = 0;
	for (ll bit = 0; bit < (1 << n); ++bit) {
		bool flag = true;
		ll preans = 0;
		for (ll i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				++preans;
				for (auto p : v[i]) {
					if ((1 << p.first) & bit) {
						if (p.second == 0)flag = false;
					}
					else {
						if (p.second == 1)flag = false;
					}
				}
			}
		}
		if (flag)ans = max(ans, preans);
	}
	cout << ans << endl;
}
