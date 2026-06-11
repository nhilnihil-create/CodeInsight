#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
const lli M=998244353,N=3e3+5;
lli dp[N][N];

lli add(lli a, lli b)
{
	lli res = a + b;
	if(res >= M)
		return res - M;
	return res;
}
 
lli mul(lli a, lli b)
{
	lli  res = a * b;
	if(res >= M)
		return res % M;
	return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lli n,s;
    cin>>n>>s;
    lli i,j,a[n+1];
    
    for(i=1;i<=n;i++) cin>>a[i];
    
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=s;j++) dp[i][j]=mul(2LL, dp[i-1][j]);                                //for current value we can add it or not so we have 2 choice
        for(j=0;j<=s;j++) if(j+a[i]<=s) dp[i][j+a[i]]=add(dp[i][j+a[i]], dp[i-1][j]);   //if current value include in total sum
    }
    cout<<dp[n][s];
    return 0;
}