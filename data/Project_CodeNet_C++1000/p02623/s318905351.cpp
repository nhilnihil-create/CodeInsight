#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i=0;i<n;i++)
    cin>>a[i];
    for(ll i=0;i<m;i++)
    cin>>b[i];
    vector<ll> dp1(n,0);
    dp1[0]=a[0];
    vector<ll> dp2(m,0);
    dp2[0]=b[0];
    for(ll i=1;i<n;i++)
    dp1[i]=dp1[i-1]+a[i];
    for(ll i=1;i<m;i++)
    dp2[i]=dp2[i-1]+b[i];
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll val=k-dp1[i];
        
        if(val<0)
        break;
        ll p=upper_bound(begin(dp2),end(dp2),val)-begin(dp2);
        // cout<<i<<" "<<p<<endl;
        ans=max(ans,i+p+1);

    }
    for(ll i=0;i<m;i++)
    {
        ll val=k-dp2[i];
        if(val<0)
        break;
        ll p=upper_bound(begin(dp1),end(dp1),val)-begin(dp1);
        ans=max(ans,i+p+1);
    }
    cout<<ans<<endl;

}