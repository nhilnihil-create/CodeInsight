#include <bits/stdc++.h>
using namespace std;

char str[25]; 
long long dp[10][10] = {0};
long long MI[10] = {1}, cnt = 0;

int main () {
	for (int i = 1; i <= 6; ++i)
		MI[i] = MI[i-1] * 10;
	cin >> str;
	int len = strlen (str);
	for (int i = 1; i < len-1; ++i) {
		cnt *= 10;
		cnt += (str[i]-'0');
	}
	++cnt;
	for (long long i = 1; i <= 9; ++i)
		for (long long j = 1; j <= 9; ++j) {
			if (i == j && (len == 1 && i <= str[0]-'0' || len > 1))
				dp[i][j]++;
			if (len == 1)
				continue;
			for (int k = 1; k < len-1; ++k)
				dp[i][j] += MI[k-1];
			if (i < str[0]-'0') {
				dp[i][j] += MI[len-2];
				continue;
			}
			if (i > str[0]-'0')
				continue;
			dp[i][j] += cnt;
			if (j > str[len-1]-'0')
				--dp[i][j];
		}
	long long ans = 0;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			ans += dp[i][j] * dp[j][i];
	cout << ans << endl;
	return 0;
}