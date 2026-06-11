#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define int long long
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

// const int mask = (1 << 15);

const int nax = 1005;
const int constmask = (1 << 15);
int a[nax], b[nax];
int dp[nax][(1 << 15)]; // minimum cost to cover with first i item and mask "mask"
const int INF = 1e9;

int calc(int i, int mask) {
	if (i <= 0) {
		if (mask != 0) return INF;
		else if (mask == 0) return 0;
	}
	if (dp[i][mask] != -1) return dp[i][mask];

	int ret = INF;

	// chon cai thu i:
	int nmask = (mask ^ (mask & b[i]));

	// cerr << "nmask - mask - b[i]: " << nmask << ' ' << mask << ' ' << b[i] << '\n';

	ret = min(ret, calc(i - 1, nmask) + a[i]);
	ret = min(ret, calc(i - 1, mask));

	return (dp[i][mask] = ret);
}

void solve() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < nax; ++i) {
		for (int m = 0; m < constmask; ++m) {
			dp[i][m] = -1;
		}
	}

	for (int i = 1; i <= m; ++i) {
		int num;
		cin >> a[i] >> num;

		for (int j = 1; j <= num; ++j) {
			int c;
			cin >> c;
			--c;

			b[i] |= (1 << c);
		}
	}

	cout << ((calc(m, (1 << n) - 1) != INF) ? calc(m, (1 << n) - 1) : -1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}