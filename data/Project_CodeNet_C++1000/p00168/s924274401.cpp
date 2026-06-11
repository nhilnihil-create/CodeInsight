#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<algorithm>

#define N_MAX 30

int main(){
	while (1){
		int n, dp[N_MAX + 1];
		scanf("%d", &n);
		if (n == 0)
			break;
		std::fill(dp, dp + n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i){
			for (int j = 1; j <= 3; ++j){
				if (j <= i){
					dp[i] += dp[i - j];
				}
			}
		}
		int day = (dp[n] % 3650 == 0) ? dp[n] / 3650 : dp[n] / 3650 + 1;
		printf("%d\n", day);
	}
	return 0;
}