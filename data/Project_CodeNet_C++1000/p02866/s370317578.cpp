#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,ll>P;
const int mod =998244353;

int main()
{
    int n;
    cin>>n;
    vector<ll> d(n);
    rep(i,n)
    {
        cin>>d[i];
    }
    if(d[0]!=0)
    {
        cout<<0;
        return 0;
    }
    map<int,int> dc;
    rep(i,n)
    {
        dc[d[i]]++;
    }
    if(dc[0]!=1)
    {
        cout<<0;
        return 0;
    }
    ll ans=1;
    P prev=P(0,1);
    for(auto v:dc)
    {
        if(v.first-prev.first>1)
        {
            cout<<0;
            return 0;
        }

        if(v.first>1)
        {
            rep(i,v.second)
            {
                ans=ans*prev.second%mod;
            }
        }
        prev=v;
    }
    cout<<ans;

}