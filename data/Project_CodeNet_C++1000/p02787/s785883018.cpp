#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5, maxs = 2e4+5, inf = 1e9;
int n, h, a[maxn], b[maxn], dp[maxs];

int main(){
	scanf("%d %d", &h, &n);
	for(int i = 1; i<=n; i++) scanf("%d %d", &a[i], &b[i]);
	fill(dp+1, dp+maxs, inf);
	for(int i = 1; i<=n; i++){
		for(int s = a[i]; s<maxs; s++) dp[s] = min(dp[s], dp[s-a[i]] + b[i]);
	}
	printf("%d\n", *min_element(dp+h, dp+maxs));
	return 0;
}