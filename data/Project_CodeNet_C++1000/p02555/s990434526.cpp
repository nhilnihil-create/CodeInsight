#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
	int s;
	cin >> s;
	vector<long long> dp(s + 1);
	dp[0] = 1;
	for(int i = 3; i <= s; i++) {
		dp[i] = (dp[i - 1] + dp[i - 3]) % mod;
	}
	cout << dp[s] << endl;
    return 0;
}
