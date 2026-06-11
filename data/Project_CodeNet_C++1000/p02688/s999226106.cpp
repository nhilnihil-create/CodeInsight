#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll n,k,d,x;
    map<ll,ll> m;
    cin>>n>>k;
    for(ll i=1;i<=k;i++)
    {
        cin>>d;
        for(ll it=0;it<d;it++)
        {
            cin>>x;
            m[x]=1;
        }
    }
    cout<<n-m.size();
}

    
