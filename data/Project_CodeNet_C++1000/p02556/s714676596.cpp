#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000000+5];
ll arr[1000000+5];
/*arr[0]=1;
dp[0]=1;*/
int main()
{
    /*ll n,x=1,i;
    cin>>n;
    ll mod=1000000007;
    ll dp[n+2]
    for(i=1;i<=n-1;i++)
    {
        x=x*2;
        x=x%mod;
    }
    x=x+n-1;
    x=x%mod;
    cout<<x;*/
    /*ll n;
    cin>>n;
    ll a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>n;
    }*/
    ll n,i,x,y,j;
    cin>>n;
    ll dis[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
    std::vector<ll> low(4,INT_MAX);
    std::vector<ll> high(4,INT_MIN);
    for(i=0;i<n;i++)
    {   
        cin>>x>>y;
        for(j=0;j<4;j++)
        {
            low[j]=min(low[j],x*dis[j][0]+y*dis[j][1]);
            high[j]=max(high[j],x*dis[j][0]+y*dis[j][1]);
        }
    }
    ll ans=0;
    for(i=0;i<4;i++)
    {
        ans=max(ans,abs(high[i]-low[i]));
    }
    cout<<ans;
}
