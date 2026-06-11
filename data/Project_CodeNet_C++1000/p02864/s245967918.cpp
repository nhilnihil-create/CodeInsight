#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int a[305];
long long dp[305][305];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) dp[i][j] = INF;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int lt = 0; lt < i; lt++) {
				if (i - lt - 1 > j) continue;
				int cost;
				if (a[i] < a[lt]) cost = 0;
				else cost = a[i] - a[lt];
				
				dp[i][j] = min(dp[i][j], dp[lt][j - (i - lt - 1)] + cost);
			}
		}
	}
	
	long long res = INF;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j + n - i > k) continue;
			res = min(res, dp[i][j]);
		}
	}
	
	printf("%lld\n", res);
}
