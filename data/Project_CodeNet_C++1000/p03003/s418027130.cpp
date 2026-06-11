#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;

int n,m;
int a[2005],b[2005],dp[2005][2005];

signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=m;i++)  cin>>b[i];
	
	for (int i=0;i<=m;i++)  dp[0][i]=1;
	for (int i=0;i<=n;i++)  dp[i][0]=1;	
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i+j==0)  continue;
			else
			{
				dp[i][j]=((dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod+mod)%mod;
				if (a[i]==b[j])  dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
			}
		}
	}
	cout<<dp[n][m]<<endl;
	
	return 0;
}