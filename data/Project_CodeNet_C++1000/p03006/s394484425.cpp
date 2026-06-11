#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<ll,ll>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<P> ab(n);
    rep(i,n)cin>>ab[i].first>>ab[i].second;
    
    map<P,int> c;
    rep(i,n)
    {
        rep(j,n)
        {
            if(i==j)continue;
            ll x=ab[j].first-ab[i].first;
            ll y=ab[j].second-ab[i].second;
            c[P(x,y)]++;
        }
    }
    int maxc=0;
    for(auto v: c)
    {
        maxc=max(maxc,v.second);
    }
    cout<<n-maxc;
    
 
 
}