#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <numeric>
#include <random>
#include <memory>
#include <chrono>
#include <functional>
#include <unordered_set>
#include <cstring>
#include <cassert>
#include <bitset>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif
//#define int ll
//#pragma GCC optimize("Ofast")


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
#define sz(x) int((x).size())

#ifndef LOCAL
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#else
	mt19937 rng(228);
#endif

const int N = 1e3 + 7;
const int inf = INT_MAX / 2;
const ll INF = LLONG_MAX / 3;
const int MOD = 998244353;
const ld eps = 1e-6;
const string cars[] = {"🚗", "🚕", "🚙"};

int a[N][N], pos[N][N], dp[N][N], c[N][N], n;

void calc(int x, int y) {
	if (dp[x][y] || x == 0 || y == 0) {
		return;
	}
	if (c[x][y] == 1) {
		cout << "-1\n";
		exit(0);
	}
	c[x][y] = 1;

	int i = a[x][pos[x][y] - 1];
	int j = a[y][pos[y][x] - 1];

	calc(x, i);
	calc(y, j);

	dp[x][y] = max(dp[x][i], dp[y][j]) + 1;
	c[x][y] = 2;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(9);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			cin >> a[i][j];
			pos[i][a[i][j]] = j;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			calc(i, j);
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}