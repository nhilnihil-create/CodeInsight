#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18L;
const ll NINF = -1e18L;

struct Point {
	ll x;
	ll y;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<Point> a(n);
	ll mxS = NINF;
	ll mxD = NINF;
	ll mnS = INF;
	ll mnD = INF;
	for (auto& p: a) {
		cin >> p.x >> p.y;
		ll s = p.x + p.y;
		ll d = p.x - p.y;
		mxS = max(mxS, s);
		mnS = min(mnS, s);
		mxD = max(mxD, d);
		mnD = min(mnD, d);
	}
	ll ans = 0;
	for (auto p: a) {
		ll d1 = p.x + p.y - mxS;
		ll d2 = p.x + p.y - mnS;
		ll d3 = p.x - p.y - mxD;
		ll d4 = p.x - p.y - mnD;
		ans = max({ans, d1, d2, d3, d4});
	}
	cout << ans << endl;
	return 0;
}