#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

const int N = 2e3 + 7;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int dp[N][N];
int ps[N][N];

vector<int> s;
vector<int> t;

int calc(int i, int j) {
	if (dp[i][j] == -1) {
		dp[i][j] = 0;
		for (int i1 = 0; i1 < i; i1++) {
			for (int j1 = 0; j1 < j; j1++) {
				if (s[i1] == t[j1]) {
					dp[i][j] = add(dp[i][j], calc(i1, j1));
				}
			}
		}
		dp[i][j]++;
	}
	return dp[i][j];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	int n, m;
	cin >> n >> m;
	s.resize(n);
	t.resize(m);
	for (auto &x : s) cin >> x;
	for (auto &x : t) cin >> x;
	int ans = 0;
	auto gt = [&](int i, int j) {
		if (i >= 0 && j >= 0) return ps[i][j];
		else return (int)0;
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i][j] = gt(i - 1, j - 1);
				dp[i][j] = add(dp[i][j], 1);
				ans = add(ans, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
			ps[i][j] = gt(i - 1, j) + gt(i, j - 1) - gt(i - 1, j - 1) + dp[i][j];
			ps[i][j] %= MOD;
			ps[i][j] += MOD;
			ps[i][j] %= MOD;	
		}
	}
	ans = add(ans, 1);
	cout << ans << endl;
}
