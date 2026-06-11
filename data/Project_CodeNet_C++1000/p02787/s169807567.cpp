#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5, maxs = 2e4+5, inf = 1e9;
int n, h, a[maxn], b[maxn], dp[maxn][maxs];

int main(){
	scanf("%d %d", &h, &n);
	for(int i = 1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
	fill(dp[0]+1, dp[0]+maxs, inf);
	for(int i = 1; i<=n; i++){
		for(int s = 0; s<maxs; s++){
			dp[i][s] = dp[i-1][s];
			if (s>=a[i]) dp[i][s] = min(dp[i][s], dp[i][s-a[i]]+b[i]);
		}
	}
	printf("%d\n", *min_element(dp[n]+h, dp[n]+maxs));
	return 0;
}