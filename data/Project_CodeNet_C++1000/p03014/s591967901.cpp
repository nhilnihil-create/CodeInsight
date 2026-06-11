#include <bits/stdc++.h>
using namespace std;

const int M=2005;
char g[M][M];

int dp[M][M][4];

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",g[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(g[i][j]=='#') continue;
			dp[i][j][0]=i==0?1:(dp[i-1][j][0]+1);
			dp[i][j][1]=j==0?1:(dp[i][j-1][1]+1);
		}
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--)
		{
			if(g[i][j]=='#') continue;
			dp[i][j][2]=i==n-1?1:(dp[i+1][j][2]+1);
			dp[i][j][3]=j==m-1?1:(dp[i][j+1][3]+1);
		}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(g[i][j]=='#') continue;
			ans=max(ans,dp[i][j][0]+dp[i][j][1]+dp[i][j][2]+dp[i][j][3]-3);
		}
	printf("%d\n",ans);
	return 0;
}