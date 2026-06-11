#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
const ll mod = 1e9 + 7;
int main()
{
	SPEED
	ll s;
	cin >> s;

	vector<ll> dp(s+10);
	if(s<3)
	{
		cout << 0;
		return 0;
	}

	dp[0] = 1;

	for (ll sum = 3; sum <= s; ++sum)
	{
		for (ll coins = 3; coins <= sum; ++coins)
		{
			dp[sum] += dp[sum-coins];
			dp[sum] %= mod;
		}
	}

	// for (int i = 0; i < s+1; ++i)
	// {
	// 	cout << dp[i] << " ";
	// }
	cout << (dp[s])%mod;
	return 0;
}