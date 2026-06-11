#include<bits/stdc++.h>
using namespace std;
long long dp[1000100][4];
const int mod=1000000007;
int main()
{
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[0][0]=8;
	dp[0][1]=1;
	dp[0][2]=1;
	dp[0][3]=0;
	for(int i=1;i<=n-1;i++)
	{
		dp[i][0]=(dp[i-1][0]*8+mod)%mod;
		dp[i][1]=(dp[i-1][0]+(dp[i-1][1]*9)%mod+mod)%mod;
		dp[i][2]=(dp[i-1][0]+(dp[i-1][2]*9)%mod+mod)%mod;
		dp[i][3]=(dp[i-1][1]+dp[i-1][2]+(dp[i-1][3]*10)%mod+mod)%mod;
	}
	cout<<dp[n-1][3]%mod<<endl;
	return 0;
}