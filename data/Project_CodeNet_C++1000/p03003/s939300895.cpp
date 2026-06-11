#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()

const long long MOD = 1e9 + 7;
const int MAXN = 2001;
long long dp[MAXN][MAXN];
int s[MAXN], t[MAXN];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &t[i]);

	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 0; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + MOD) % MOD;
			if (s[i] == t[j]) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
		}
	}

	/*
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) printf("%lld ", dp[i][j]);
		puts("");
	}
	*/

	printf("%lld\n", dp[n][m]);
}
