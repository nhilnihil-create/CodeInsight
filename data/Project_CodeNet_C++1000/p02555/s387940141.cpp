#include <bits/stdc++.h>

using namespace std;

#define MOD 1'000'000'007

typedef long long int ll;
long long int dp[2001];

ll getWays(int s)
{
	if(s == 0) return 1;
	if(s == 3) return 1;

	if(s < 3) return 0;
	

	if(dp[s] != -1) return dp[s];
	ll ways = 0;
	for(int i = 3; i <= s; ++i)
	{
		ways += getWays(s - i);
		ways %= MOD;
	}
	 
	dp[s] = ways % MOD;
	return dp[s];
}
int main()
{
	memset(dp, -1, sizeof(dp));
	
	int s;
	cin >> s;
	cout << getWays(s) % MOD;

	return 0;
}