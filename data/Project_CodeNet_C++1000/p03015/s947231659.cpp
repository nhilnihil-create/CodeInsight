#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

char s[maxn];
const ll mod=1000000007;
ll dp[maxn][2];

int main()
{
	scanf("%s",s+1); ll len=strlen(s+1),p=1,cnt=0,ans=0,a1=0;
	for(int i=1;i<=len;i++) if(s[i]=='1') cnt++;
	dp[len+1][0]=1;
	for(int i=len;i>=1;i--)
	{
		if(s[i]=='1')
		{
			dp[i][0]=(dp[i+1][1]+dp[i+1][0]*3)%mod;
			dp[i][1]=(dp[i+1][1]*2);
		}
		else
		{
			dp[i][0]=dp[i+1][0];
			dp[i][1]=(dp[i+1][1]*3+dp[i+1][0]*2)%mod;
		}
	}
	//for(int i=1;i<=len;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	cout<<dp[1][0]<<endl;
	return 0;
}