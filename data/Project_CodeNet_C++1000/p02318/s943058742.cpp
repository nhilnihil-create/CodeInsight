#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1001][1001];

int main()
{
	string s,t;
	cin >> s >> t;
	int n = s.size(),m = t.size();
	for(int i = 0;i<n+1;i++)
	{
		dp[i][0] = i;
	}
	for(int i = 0;i<m+1;i++)
	{
		dp[0][i] = i;
	}
	for(int i = 1;i<n+1;i++)
	{
		for(int j = 1;j<m+1;j++)
		{
			int cost = s[i-1]!=t[j-1];
			dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cost});
		}
	}
	cout<<dp[n][m]<<endl;
}
