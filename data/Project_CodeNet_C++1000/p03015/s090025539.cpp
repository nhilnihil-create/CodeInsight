#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll dp[100004][2];

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	dp[0][1] = 1;
	for(int i = 0;i<n;i++)
	{
		if(s[i]=='0')
		{
			(dp[i+1][0] += dp[i][0]*3)%=MOD;
			(dp[i+1][1] += dp[i][1]);
		}
		else
		{
			(dp[i+1][0] += dp[i][0]*3)%=MOD;
			(dp[i+1][1] += dp[i][1]*2)%=MOD;
			(dp[i+1][0] += dp[i][1]);
		}
	}
	cout<<(dp[n][1]+dp[n][0])%MOD<<endl;

}
