#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fun(ll lo, ll hi,ll index, vector<pair<ll,ll>> &vec,map<pair<ll,ll>,ll> &ma)
{
    if(lo>hi)
    return 0;
    if(lo==hi)
    {
        ll temp=(vec[index].first)*abs(lo-vec[index].second);
        ma[make_pair(lo,hi)]=temp;
        return temp;
    }
    else
    {
        if(ma.find(make_pair(lo+1,hi))==ma.end())
        {
            fun(lo+1,hi,index+1,vec,ma);
        }
        
        if(ma.find(make_pair(lo,hi-1))==ma.end())
        {
            fun(lo,hi-1,index+1,vec,ma);
        }
        
        ll a=vec[index].first;
        ll b=vec[index].second;
        ll temp=std::max(a*abs(lo-b)+ma[make_pair(lo+1,hi)],a*abs(hi-b)+ma[make_pair(lo,hi-1)]);
        ma[make_pair(lo,hi)]=temp;
        return temp;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;++i)
    {
        ll a;
        cin>>a;
        vec[i]=make_pair(a,i);
    }
    sort(vec.rbegin(),vec.rend());
    map<pair<ll,ll>,ll> ma;
    ll ans=fun(0,n-1,0,vec,ma);
    cout<<ans<<"\n";

}
