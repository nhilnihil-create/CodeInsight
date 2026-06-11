#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int h, w, m;
	cin >> h >> w >> m;
	int x[m], y[m];
	set<pair<int, int>> s;
	vector<int> H(h), W(w);
	rep(i, m) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		s.insert({x[i], y[i]});
		H[x[i]]++;
		W[y[i]]++;
	}
	int maxh = 0, maxw = 0;
	rep(i, h) maxh = max(maxh, H[i]);
	rep(i, w) maxw = max(maxw, W[i]);
	set<int> X, Y;
	rep(i, h) {
		if (H[i] == maxh) X.insert(i);
	}
	rep(i, w) {
		if (W[i] == maxw) Y.insert(i);
	}
	for (auto nx : X) {
		for (auto ny : Y) {
			if (s.count({nx, ny}) == 0) {
				cout << maxh + maxw << "\n";
				return 0;
			}
		}
	}
	cout << maxh + maxw - 1 << "\n";
	return 0;
}