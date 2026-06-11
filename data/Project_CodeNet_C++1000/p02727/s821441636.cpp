#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll X,Y,A,B,C; cin>>X>>Y>>A>>B>>C; vector<ll> hoge={A,B,C};
  vector<vector<ll>> vec(3,vector<ll>(0));
  rep(i,3) rep(j,hoge[i]) {ll piyo; cin>>piyo; vec.at(i).push_back(piyo);}
  for(auto &svec:vec) sort(svec.rbegin(),svec.rend());
  
  vector<ll> next={0,0,0};
  ll ans=0;
  rep(i,X+Y){
    ll sans=0,sep=-1;
    rep(j,3){
      if(j==0&&(next[0]>=X||next[0]>=A)) continue;
      if(j==1&&(next[1]>=Y||next[1]>=B)) continue;
      if(j==2&&next[2]>=C) continue;
      if(chmax(sans,vec[j][next[j]])) sep=j;
    }
    //cout<<sans<<endl;
    ans+=sans; next[sep]++;
  }
  
  cout<<ans<<endl;
  
  return 0;
}