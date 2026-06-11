#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	string s;
	cin >> s;
	
	ll ans = 0;
	ll dp[2019] = {};
	dp[s[0] - '0'] = 1;
	for(int i = 1; i<s.size(); i++)
	{
		int d = s[i] - '0';
		ll tdp[2019] = {};
		tdp[d] = 1;
		for(int j = 0; j<2019; j++)
		{
			if(dp[j] > 0)
			{
				ll rem = (10*j + d)%2019;
				if(rem == 0) ans += dp[j];
				tdp[rem] += dp[j];
			}
		}
		for(int j = 0; j<2019; j++)
		{
			dp[j] = tdp[j];
		}
	}
	cout << ans;
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

