#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  vector<vector<vector<ll>>> vec(N,vector<vector<ll>>(0));
  rep(i,N)
  {
    ll A; cin>>A;
    rep(j,A)
    {
      ll x,y; cin>>x>>y; x--;
      vec.at(i).push_back({y,x});
    }
  }
  ll ans=0;
  rep(i,1<<N)
  {
    bitset<15> i2(i);
    ll ans2=0;
    rep(j,N)
    {
      if(i2.test(j))
      {
        ans2++;
        for(auto p:vec.at(j))
        {
          ll x=p.at(1),y=p.at(0);
          if(y==1&&!i2.test(x)) {goto OUT;}
          if(y==0&&i2.test(x)) {goto OUT;}
        }
      }
    }
    ans=max(ans,ans2);
    OUT:;
    //cout<<i<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}