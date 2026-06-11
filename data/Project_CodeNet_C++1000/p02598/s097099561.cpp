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

	int n, k;
	cin >> n >> k;
	int a[n];
	rep(i, n) cin >> a[i];
	int l = 0, r = 1000000001;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int cnt = 0;
		rep(i, n) cnt += (a[i] + m - 1) / m - 1;
		if (cnt <= k)
			r = m;
		else
			l = m;
	}
	cout << r << endl;
	return 0;
}