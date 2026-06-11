#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;
const int mxn = 3e3;

long long dp[mxn + 11][mxn + 11];
int a[mxn + 11];

int main(){
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= s; j++){
			dp[i + 1][j] += 2 * dp[i][j];
			dp[i + 1][j] %= md;
			if (j + a[i] <= s){
				dp[i + 1][j + a[i]] += dp[i][j];
				dp[i + 1][j + a[i]] %= md;
			}
		}
	}
	printf("%d\n", dp[n][s]);
	return 0;
}
