#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack> 
#include <bitset>
#include <queue>
#include <assert.h>
#include <unordered_map>
using namespace std;

const int N = 3010;
const int mod = 998244353;
int dp[N][N];
int a[N];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	// dp[i][j]
	// first i number, sum of T is j
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == 0) continue;
			// not in S, not int T
			add(dp[i + 1][j], dp[i][j]);
			// in S, not int T
			add(dp[i + 1][j], dp[i][j]);
			// in T
			if (j + a[i + 1] <= m) add(dp[i + 1][j + a[i + 1]], dp[i][j]);
		}

	cout << dp[n][m] << endl;
	return 0;
}
