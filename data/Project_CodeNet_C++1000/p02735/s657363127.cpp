#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;	

int dp[102][102];
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli t,n,m,r,temp,temp1,temp2,temp3,k,a,b,c,d,count,x,y;
	
	cin>>n>>m;
	int grid[n+2][m+2];	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=1e9+7;
		}
	}
	char ch;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='#')
			{
				grid[i][j]=1;
			}
			else
			{
				grid[i][j]=0;
			}
		}
	}
	
	if(grid[1][1]==0)
	dp[1][1]=0;
	else
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i>1)
			{
				if(grid[i-1][j]==0&&grid[i][j]==1)
				{
					dp[i][j]=1+dp[i-1][j];
				}
				else
				{
					
					dp[i][j]=dp[i-1][j];
				}
			}
			
			if(j>1)
			{
				if(grid[i][j-1]==0&&grid[i][j]==1)
				{
					
					dp[i][j]=min(1+dp[i][j-1],dp[i][j]);
				}
				else
				{
					dp[i][j]=min(dp[i][j-1],dp[i][j]);
				}
			}
		}
	}
	

	cout<<dp[n][m];
}
