#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[200010];
int b[200010];

ll nCr(ll n, ll r)
{
    if(n<r)return 0;
    ll b=1;
    ll a=1;
    for(ll i=0;i<r;i++)
    {
        b*=(n-i);
        a*=(r-i);
    }
    ll ret=b/a;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }

    ll sumall=0;

    for(int i=1;i<=n;i++)sumall+=nCr(b[i],2);

    for(int i=0;i<n;i++)
    {
        ll ans=sumall-nCr(b[a[i]],2)+nCr(b[a[i]]-1,2);
        cout<<ans<<"\n";
    }

    return 0;
}
