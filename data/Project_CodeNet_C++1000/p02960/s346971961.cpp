#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100001][13];
const int MOD = 1e9+7;
int main()
{
	string s;
	cin >> s;
	dp[0][0] = 1;

	int n = s.size();

	for(int i = 0;i<n;i++)
	{
		if(s[i]=='?')
		{
			for(int j = 0;j<10;j++)
			{
				for(int k = 0;k<13;k++)
				{
					int x = (k*10+j)%13;
					(dp[i+1][x] += dp[i][k])%=MOD;
				}
			}
		}
		else
		{
			int k = s[i] - '0';
			for(int j = 0;j<13;j++)
			{
				int x  = (j*10 + k)%13;
				(dp[i+1][x] += dp[i][j])%=MOD;
			}
		}
	}
	cout<<dp[n][5]<<endl;

}