#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[200005];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll l=0,r=1e9;
    while(l+1<r)
    {
        ll m=(l+r)/2;
        ll s=0;
        for(ll i=0;i<n;i++)
        {
            s+=(a[i]+m-1)/m-1;
        }
        if(s<=k)
            r=m;
        else
            l=m;

    }
    cout<<r<<endl;
}
