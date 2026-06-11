#include <bits/stdc++.h>

using namespace std;

long long dp[105][10], cnt[105];

int main() {
	int k;
	scanf("%d", &k);
	
	if (k <= 9) return 0 * printf("%d\n", k);
	
	for (int i = 0; i <= 9; i++) dp[1][i] = 1LL;
	cnt[1] = 9;
	
	int len = -1;
	
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j];
			if (j + 1 <= 9) dp[i][j] += dp[i - 1][j + 1];
		}
		
		cnt[i] = cnt[i - 1];
		for (int j = 1; j <= 9; j++) cnt[i] += dp[i][j];
		
		if (cnt[i] >= k) {
			len = i;
			break;
		}
	}
	
	long long cur = cnt[len - 1];
	int curDigit = -1;
	for (int i = 1; i <= 9; i++) {
		if (cur + dp[len][i] >= k) {
			curDigit = i;
			k -= cur;
			break;
		}
		cur += dp[len][i];
	}
	
	printf("%d", curDigit);
	
	for (int i = len - 1; i >= 1; i--) {
		long long sum = 0;
		for (int j = max(0, curDigit - 1); j <= min(9, curDigit + 1); j++) {
			if (sum + dp[i][j] >= k) {
				k -= sum;
				printf("%d", j);
				curDigit = j;
				break;
			}
			sum += dp[i][j];
		}
	}
	printf("\n");
}
