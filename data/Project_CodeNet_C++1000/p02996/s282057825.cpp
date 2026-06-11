#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;
	for (ll i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	ll now = 0;
	for (auto p : v) {
		now += p.second;
		if (now > p.first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
