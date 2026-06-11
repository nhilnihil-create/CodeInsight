#include<bits/stdc++.h>
using namespace std;

long long int n,k,i,j,a,b,c,dp[100010][3],ans;
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>a>>b>>c>>s;
	dp[0][1]=0;dp[0][2]=0;dp[0][3]=0;
	for (i=1;i<n+1;i++) for (j=1;j<4;j++)
	{
		dp[i][j]=0;
		if (j==1 && s[i-1]=='s') dp[i][j]=a;
		if (j==2 && s[i-1]=='p') dp[i][j]=b;
		if (j==3 && s[i-1]=='r') dp[i][j]=c;
		if (i>k) dp[i][j]=dp[i][j]+max(dp[i-k][j%3+1],dp[i-k][(j+1)%3+1]);
	}
	ans=0;
	for (i=0;i<min(n,k);i++) ans=ans+max(dp[n-i][1],max(dp[n-i][2],dp[n-i][3]));
	cout<<ans;
}