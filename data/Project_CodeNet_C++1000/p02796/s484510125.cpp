#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<P> m(n);
    vector<P> xl(n);
    rep(i,n)
    {
        cin>>xl[i].first>>xl[i].second;
    }
    rep(i,n)
    {
        
        m[i].first=xl[i].first+xl[i].second;
        m[i].second=xl[i].first-xl[i].second;
    }
    sort(m.begin(),m.end());
    ll prev=-1e9;
    int ans=0;
    rep(i,n)
    {
        if(m[i].second>=prev)
        {
            ans++;
            prev=m[i].first;
        }
    }
    cout<<ans;
}
