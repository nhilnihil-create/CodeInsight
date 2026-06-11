#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<long long> dp(2020, 0);
	string s;
	cin >> s;
	int len = s.length();
	long long cnt = 0;
	for(int i = 0; i < len; i++) {
		vector<long long> new_dp(2020, 0);
		dp[0] += 1;
		for(int j = 0; j < 2019; j++) {
			new_dp[((j*10)+s[i]-'0')%2019] += dp[j];
		}
		dp = new_dp;
		cnt += dp[0];
	}
	printf("%lld\n", cnt);
}