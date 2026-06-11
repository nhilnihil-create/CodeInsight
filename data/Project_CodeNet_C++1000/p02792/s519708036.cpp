#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[15][15] = {0}, ans = 0;

int fun (int xx) {
	while (xx >= 10)
		xx /= 10;
	return xx;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tem = fun (i);
		dp[tem][i%10]++;
	}
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			ans += dp[i][j]*dp[j][i];
	printf ("%lld", ans);
	return 0;
}
	