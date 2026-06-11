#include<bits/stdc++.h>
using namespace std;

long long int n,i,mod,dp[100010][15],j,k,x;
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	n=s.size();mod=1e9+7;
	for (i=0;i<13;i++) for (j=0;j<n+1;j++) dp[j][i]=0;dp[0][0]=1;
	for (i=1;i<n+1;i++) if (s[i-1]!='?')
	{
		x=(s[i-1]-'0');
		for (j=0;j<13;j++) dp[i][(j*10+x)%13]=(dp[i][(j*10+x)%13]+dp[i-1][j])%mod;
	}
	else
	{
		for (j=0;j<13;j++) for (x=0;x<10;x++)
		dp[i][(j*10+x)%13]=(dp[i][(j*10+x)%13]+dp[i-1][j])%mod;
	}
	cout<<dp[n][5];
}
