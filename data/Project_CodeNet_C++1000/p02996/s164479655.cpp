#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<pair<ll, ll>> pa;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		pa.push_back({ b,a });
	}
	sort(pa.begin(), pa.end());
	ll time = 0;
	bool can = true;
	for (ll i = 0; i < n; i++) {
		time += pa[i].second;
		if (pa[i].first < time) can = false;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}