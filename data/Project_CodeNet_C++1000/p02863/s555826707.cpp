#include <bits/stdc++.h>
 
using namespace std;

int dp[3001][3001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t,a,b;
	vector <pair<int,int>> v;

	cin >> n >> t;

	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	sort(v.begin(),v.end());
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<t;j++)
		{
			if(dp[i][j]==-1)
			{
				continue;
			}
			int T = min(j + v[i].first,t);
			dp[i+1][T] = max(dp[i+1][T],dp[i][j] + v[i].second);
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		}
	}

	int res = 0;

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=t;j++)
		{
			res = max(res,dp[i][j]);
		}
	}

	cout << res << '\n';
	return 0;
}