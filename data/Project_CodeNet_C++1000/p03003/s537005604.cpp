#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2010][2010];
ll sum[2010][2010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll s[n+1];
    ll t[m+1];
    for(ll i=1;i<=n;i++)
        cin>>s[i];
    for(ll i=1;i<=m;i++)
        cin>>t[i];
    dp[0][0]=1;
    ll p=1000000007;
    for(ll i=1;i<=n;i++)
    {
        dp[i][0]=0;
        sum[i][0]=0;
    }
    for(ll i=1;i<=m;i++)
    {
        dp[0][i]=0;
        sum[0][i]=0;
    }
    sum[0][0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s[i]!=t[j])
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=(sum[i-1][j-1]+1)%p;
            }
            sum[i][j]=(((sum[i-1][j]+sum[i][j-1])%p-sum[i-1][j-1]+p)%p+dp[i][j])%p;
        }
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
            sum=(sum+dp[i][j])%p;
    }
    cout<<(sum+1)%p;
}