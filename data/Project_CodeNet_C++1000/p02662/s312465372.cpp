#include<bits/stdc++.h>

using namespace std;
const long long mod=998244353;
const int N=3e3+10;
long long dp[N][N];
int a[N],n,s;
void add(long long &x,long long y)
{
    x=(x+y)%mod;
}
int main()
{
    cin>>n>>s; 
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;++j) 
		dp[i][j]=dp[i-1][j]*2%mod;
 
        for(int j=s;j>=a[i];--j)
		{
            add(dp[i][j],dp[i-1][j-a[i]]);
        }
    }
    printf("%lld\n",dp[n][s]);
}