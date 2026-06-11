#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll NINF = -1e18;

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pair<long long, long long>> a(n);
	vector<ll> sums(n);
	vector<ll> diffs(n);
	ll mxS = NINF;
	ll mxD = NINF;
	ll mnD = INF;
	ll mnS = INF;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		ll s = a[i].first + a[i].second;
		ll d = a[i].first - a[i].second;
		mxS = max(mxS, s);
		mnS = min(mnS, s);
		mxD = max(mxD, d);
		mnD = min(mnD, d);
	}
	// sort(sums.begin(), sums.end());
	// sort(diffs.begin(), diffs.end());
	ll ans = 0;
	for (auto point: a) {
		ll x = point.first;
		ll y = point.second;
		ll d1 = abs(x + y - mxS);
		ll d2 = abs(x - y - mxD);
		ll d3 = abs(x + y - mnS);
		ll d4 = abs(x - y - mnD);
		ans = max({ans, d1, d2, d3, d4});
	}
	cout << ans << endl;

	return 0;
}