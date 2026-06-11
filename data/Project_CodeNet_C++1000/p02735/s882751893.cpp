#include <bits/stdc++.h>
#define SIZE 105
using namespace std;

char mp[SIZE][SIZE];
int dp[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0&&j==0) dp[i][j]=(mp[i][j]=='.'?0:1);
			else
			{
				int w=n+m;
				if(i>0) w=min(w,dp[i-1][j]+(mp[i-1][j]!=mp[i][j]));
				if(j>0) w=min(w,dp[i][j-1]+(mp[i][j-1]!=mp[i][j]));
				dp[i][j]=w;
			}
		}
	}
	printf("%d\n",(dp[n-1][m-1]+1)/2);
	return 0;
}