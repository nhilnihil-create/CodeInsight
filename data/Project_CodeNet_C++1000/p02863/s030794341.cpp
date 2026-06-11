#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
	int n,t;
	cin >> n >> t;
	vector<vector<int>> dp(n+1,vector<int>(t+1));
	vector<P> ab(n);
	for(int i = 0;i<n;i++)
	{
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab.begin(),ab.end(),[&](auto a,auto b){return a.first  < b.first ;});

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<=t;j++)
		{
			if(j-ab[i].first>=0)dp[i+1][j] = max(dp[i][j],dp[i][j-ab[i].first]+ab[i].second);
			else dp[i+1][j] = dp[i][j];
		}
	}
	vector<int> mx(n+1);
	for(int i = n-1;i>0;i--)
	{
		mx[i] = max(mx[i+1],ab[i].second);
	}

	int ans = dp[n][t];
	//cout << ab[0].first << ' ' << ab[0].second << endl;
	//cout << dp[1][10] << endl;
	//cout << mx[1] << endl;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<t;j++)ans = max(ans,dp[i][j]+mx[i]);
	}
	cout << ans << endl;
	
}
