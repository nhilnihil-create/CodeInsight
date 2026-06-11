#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<ll>as(a);
    vector<ll>bs(b);
    vector<ll>cs(c);
    rep(i,a)
    {
        cin>>as[i];
    }

    rep(i,b)
    {
        cin>>bs[i];
    }

    rep(i,c)
    {
        cin>>cs[i];
    }

    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    vector<ll> aan(x);
    vector<ll> ban(y);
    vector<ll> eat;
    rep(i,x)
    {
        eat.push_back(as[a-x+i]);
    }
    rep(i,y)
    {
        eat.push_back(bs[b-y+i]);
    }
    rep(i,c)
    {
        eat.push_back(cs[i]);
    }
    sort(eat.begin(),eat.end(),greater<ll>());
    ll ans=0;
    rep(i,x+y)
    {
        ans+=eat[i];
    }
    cout<<ans;
    
}
