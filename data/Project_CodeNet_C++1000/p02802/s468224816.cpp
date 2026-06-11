#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
using ll=long long;
int main()
{
    ll n,m,ac=0,wa=0;
    cin>>n>>m;
    vector<ll> a(n+1),w(n+1);
    rep(i,m)
    {
        ll x;
        string s;
        cin>>x>>s;
        if(s=="AC")
        {
            if(a[x]==0)
            {
                ac++;
                a[x]++;
            }
        }
        else if(s=="WA")
        {
            if(a[x]==0)
            {
                w[x]++;
                wa++;
            }
        }
    }
    rep(i,n) if(a[i]==0) wa-=w[i];
    cout<<ac<<" "<<wa;
}