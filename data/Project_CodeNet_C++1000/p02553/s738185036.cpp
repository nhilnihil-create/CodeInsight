#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll maxi=LLONG_MIN;
    maxi=max(maxi,a*c);
    maxi=max(maxi,a*d);
    maxi=max(maxi,b*c);
    maxi=max(maxi,b*d);
    cout<<maxi;
}
