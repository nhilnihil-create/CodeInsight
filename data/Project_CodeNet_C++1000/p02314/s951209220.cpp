#include <cstdio>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

const int inf = 1e5;

int n, m;
int c[20];
int dp[21][50001];

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		scanf("%d", &c[i]);
	}
	dp[0][0] = 0;
	fill_n(dp[0] + 1, n, inf);
	for(int i = 1; i <= m; ++i){
		rep(j, n + 1){
			dp[i][j] = dp[i - 1][j];
			if(j >= c[i - 1]){
				dp[i][j] = min(dp[i][j - c[i - 1]] + 1, dp[i][j]);
			}
		}
	}
	printf("%d\n", dp[m][n]);
	return 0;
}