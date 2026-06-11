#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll H,W,ans=0;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) cin >> S.at(i);
  vector<vector<ll>> h(H,vector<ll>(W,0)),w(H,vector<ll>(W,0));
  rep(i,H){
    ll t=0,s=0;
    while(t<W){
      while(s<W&&S.at(i).at(s)=='.'){
        s++;
      }
      for(ll j=t;j<s;j++){
        h.at(i).at(j)=s-t;
      }
      t=s+1;
      s=t;
    }
  }
  rep(j,W){
    ll t=0,s=0;
    while(t<H){
      while(s<H&&S.at(s).at(j)=='.'){
        s++;
      }
      for(ll i=t;i<s;i++){
        w.at(i).at(j)=s-t;
      }
      t=s+1;
      s=t;
    }
  }
  rep(i,H){
    rep(j,W){
      ans=max(ans,h.at(i).at(j)+w.at(i).at(j));
    }
  }
  cout << ans-1 << endl;
}
   