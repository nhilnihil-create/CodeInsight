#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	if (n % 2) {
		rep(i, m) { cout << 1 + i << " " << n - i << endl; }
	} else {
		rep(i, m) {
			if (i % 2) {
				cout << n / 2 - i / 2 << " " << (n + 1) / 2 + 2 + i / 2 << endl;
			} else {
				cout << ((1 + n - i / 2) % n == 0 ? n : (1 + n - i / 2) % n) << " " << 2 + i / 2
				     << endl;
			}
		}
	}
	return 0;
}