#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;

	int a[17], x[17][17], y[17][17];
	rep(i, 0, n) {
		cin >> a[i];
		rep(j, 0, a[i]) {
			cin >> x[i][j] >> y[i][j];
			--x[i][j];
		}
	}

	// 矛盾・真偽不明なのに正直
	int ans = 0;
	rep(bit, 0, 1 << n) {
		vector<int> st(n, 2);
		bool ok = true;
		rep(i, 0, n) {
			if (bit >> i & 1) {
				if (st[i] == 0) ok = false;
				rep(j, 0, a[i]) {
					if (st[x[i][j]] != 2 && st[x[i][j]] != y[i][j]) ok = false;
					else st[x[i][j]] = y[i][j];
				}
			}
		}

		rep(i, 0, n) {
			if ((bit >> i & 1) == 0 && st[i] == 1) {
				ok = false;
			}
          	if (bit >> i & 1 && st[i] == 0) {
              ok = false;
            }
		}

		if (ok) ans = max(ans, __builtin_popcount(bit));
	}
	cout << ans;
	return 0;
}
