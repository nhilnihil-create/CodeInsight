#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int N, W;
int v[101], w[101];
int dp[101][10001];

int main() {
	scanf("%d %d", &N, &W);
	rep(i, N) scanf("%d %d", &v[i], &w[i]);
	repr(i, N - 1) rep(j, W + 1) {
		if(j < w[i]) dp[i][j] = dp[i + 1][j];
		else {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
		}
	}
	printf("%d\n", dp[0][W]);
	return 0;
}