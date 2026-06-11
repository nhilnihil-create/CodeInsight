#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
const double pi=3.1415926535;
int n;
ll k;
ll a[maxn];
ll f[maxn];

int check(ll x)
{
    ll temp=k;
    for(int i=1;i<=n;i++)
    {
        ll t=x/f[i];
        if(a[i]>t)
        {
            temp-=a[i]-t;
        }
    }
    if(temp<0)
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>f[i];
    sort(a+1,a+1+n,greater<ll>());
    sort(f+1,f+1+n);
    ll l=0,r=1e15;
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout<<ans<<'\n';



}
