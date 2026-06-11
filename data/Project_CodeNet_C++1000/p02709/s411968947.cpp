#include <bits/stdc++.h>

using namespace std;

int a[2005];
pair <int, int> b[2005];
long long dp[2005][2005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) b[i] = make_pair(a[i], i);
	sort(b + 1, b + 1 + n, greater<pair<int, int>>());
	
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			// left
			if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1LL * b[i].first * (b[i].second - j));
			
			// right
			if (j != i)	dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1LL * b[i].first * (n - (i - j) + 1 - b[i].second)); 
		}
	}
	
	long long res = 0;
	
	for (int i = 0; i <= n; i++) res = max(res, dp[n][i]);
	
	printf("%lld\n", res);
}
