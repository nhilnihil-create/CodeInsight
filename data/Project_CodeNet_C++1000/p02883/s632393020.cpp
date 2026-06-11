#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<ll>());
    ll f[n];
    for(ll i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    ll l=0;
    ll r=1e12;
    ll ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll count=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]*f[i]>mid)
            {
                count=count+(a[i]-mid/f[i]);
            }
        }
        //cout<<mid<<count<<endl;
        if(count<=k)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
}