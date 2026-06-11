#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pp pop_back
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f0(i,a,n) for(i=a;i<n;i++)
#define f1(I,a,b) for(i=a;i<=b;i++)
#define stp setprecision
#define nl endl
#define ipt(a) for(i=0;i<n;i++)cin>>a[i];
#define pll pair<ll,ll>
#define vl vector<ll>
#define mp map<ll,ll>
int main()
{
    fast;
    ll t;
    t=1;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll s=max(a*c,a*d);
        ll k=max(b*c,b*d);
        cout<<max(s,k)<<nl;
    }
}