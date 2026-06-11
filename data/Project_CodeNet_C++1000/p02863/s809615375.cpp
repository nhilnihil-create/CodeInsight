#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
	int n,t;
	cin >> n >> t;
	vector<vector<int>> dp(n+1,vector<int>(t+1));
	vector<vector<int>> dp1(n+2,vector<int>(t+1));
	
	vector<P> ab(n);
	for(int i = 0;i<n;i++)
	{
		cin >> ab[i].first >> ab[i].second;
	}

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<=t;j++)
		{
			if(j-ab[i].first>=0)dp[i+1][j] = max(dp[i][j],dp[i][j-ab[i].first]+ab[i].second);
			else dp[i+1][j] = dp[i][j];
		}
	}
	for(int i = n+1;i>1;i--)
	{
		for(int j = 0;j<=t;j++)
		{
			if(j-ab[i-2].first>=0)dp1[i-1][j] = max(dp1[i][j],dp1[i][j-ab[i-2].first]+ab[i-2].second);
			else dp1[i-1][j] = dp1[i][j];

		}
	}
	
	
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<t;j++)ans = max(ans,dp[i-1][j]+dp1[i+1][t-1-j]+ab[i-1].second);
	}



	cout << ans << endl;
	
}
