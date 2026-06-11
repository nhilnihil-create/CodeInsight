#include <bits/stdc++.h>

using namespace std;

int a[111111];
int dp[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++) cin>>a[i];
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=int(1e9);
		for(int j=0;j<m;j++)
		{
			if(i>=a[j])
			{
				dp[i]=min(dp[i],dp[i-a[j]]+1);
			}
		}
	}
	cout<<dp[n]<<'\n';
}