#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll A,B,M;
  cin>>A>>B>>M;
  vector<ll> a(A),b(B);
  for(auto&& e: a) cin>>e;
  for(auto&& e: b) cin>>e;
  ll init=*min_element(b.begin(), b.end());
  multimap<ll, pair<ll,ll>> xyc;
  for (int i = 0; i < M; ++i)
  {
    ll x,y,c;
    cin>>x>>y>>c;
    x--;y--;
    xyc.emplace(x,make_pair(y,c));
  }
  ll ans=1LL<<60;
  for (int i = 0; i < A; ++i)
  {
    ll select=init;
    auto p=xyc.equal_range(i);
    for(auto itr=p.first;itr!=p.second;++itr)
    {
      select=min(select,
        b[(itr->second).first]
        -(itr->second).second);
    }
    ans=min(ans,select+a[i]);
  }
  cout<<ans<<endl;
}