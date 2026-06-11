#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxn = 5005;
const int mxm = 1005;
const int inf = 0x3f3f3f3f;
const ll mod= 1e9+7;

#define ms(x,y) memset(x,y,sizeof(x))
int n,m,dp[mxn][mxn],dpp[mxn][mxn],a[mxn],b[mxn];
int main()
{
	ms(dp,0);ms(dpp,0); 
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<=m;j++)
		{
			dp[i][j] = dp[i-1][j];
		}
		for(int j = a[i];j<=m;j++)
		{
			dp[i][j] = max(dp[i][j] , dp[i-1][j-a[i]] + b[i]);
		}
	}
	for(int i = n;i>=1;i--)
	{
		for(int j = 0;j<=m;j++)
		{
			dpp[i][j] = dpp[i+1][j];
		}
		for(int j = a[i];j<=m;j++)
		{
			dpp[i][j] = max(dpp[i][j] , dpp[i+1][j-a[i]] + b[i]);
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			ans = max(ans,dp[i-1][j] + dpp[i+1][m-1-j] + b[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
