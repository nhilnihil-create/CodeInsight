#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int nax=3002;
const int mod=998244353;
ll dp[nax][nax];
ll pow1(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2) ans=(1LL*ans*a)%mod;
        a=(a*1LL*a)%mod;
        b/=2;

    }
    return ans;
   
}
void add_self(ll &a ,ll b)
{
    a=(a+b)%mod;
}
int main()
{
    ll n,s;
    cin>>n>>s;
    int a[n];

for(int i=0;i<n;i++) cin>>a[i];
dp[0][0]=pow1((ll)2,n);
//cout<<dp[0][0]<<endl;
for(int i=1;i<=n;i++)
{
    for(int j=s;j>=0;j--)
    {
        if(j>=a[i-1])
        {
            ll add=pow1(2,mod-2)%mod;
           // cout<<add<<endl;
           add=(add*dp[i-1][j-a[i-1]])%mod;
        add_self(dp[i][j],add);
        }
        add_self(dp[i][j],dp[i-1][j]);
    }
}
cout<<dp[n][s]<<endl;


}
