#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll dp[n+1];
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        dp[i]=((dp[i]-i)%k+k)%k;
        //cout<<dp[i]<<" ";
    }
    //cout<<endl;
    map<ll,ll>m;
    ll mini=min(k,n);
    if(mini==n)
    {
        ll as=0;
        for(ll i=0;i<=n;i++)
        {
            m[dp[i]]+=1;
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            as+=(i->second)*(i->second-1)/2;
        }
        cout<<as;
        return 0;
    }
    for(ll i=0;i<mini;i++)
    {
        m[dp[i]]+=1;
    }
    ll ans=0;
    for(auto i=m.begin();i!=m.end();i++)
    {
        ans=ans+(i->second)*(i->second-1)/2;
    }
    //cout<<ans<<endl;
    for(ll i=mini;i<=n;i++)
    {
        m[dp[i-mini]]-=1;
        ans+=m[dp[i]];
        m[dp[i]]+=1;
    }
    cout<<ans;
}