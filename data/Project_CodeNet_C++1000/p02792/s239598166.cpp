#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll r = 10;
	vector<vector<ll>> num(r, vector<ll>(r, 0));
	for (ll i = 1; i <= n; i++) {
		vector<ll> d;
		ll iTmp = i;
		while (iTmp) {
			d.push_back(iTmp % 10);
			iTmp /= 10;
		}
		ll p = d[0];
		ll q = d[d.size() - 1];
		if (p == 0 || q == 0) continue;
			num[p][q]++;
	}
	ll ans = 0;
	for (ll p = 1; p < r; p++) {
		for (ll q = 1; q < r; q++) {
			ans += num[p][q] * num[q][p];
		}
	}
	cout << ans << endl;
	return 0;
}