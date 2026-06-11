#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;
const ll INF = 999999999999;


int main(){
  ll n;cin >> n;
  string s;cin >> s;

  vector<vector<vector<bool>>> dp(30009,vector<vector<bool>>(4,vector<bool>(1009)));
  dp.at(0).at(0).at(0) = true;
  for(ll i=0;i<n;++i){
    for(ll j=0;j<=3;++j){
      for(ll k=0;k<1000;++k){
        if( !dp.at(i).at(j).at(k) ) continue;
        dp.at(i+1).at(j).at(k) = true;
        if( j <= 2 ){
          dp.at(i+1).at(j+1).at(k*10+( s.at(i)-'0' )) = true;
        }
      }
    }
  }
  ll cnt = 0;
  for(ll i=0;i<1000;++i){
    if( dp.at(n).at(3).at(i) ) ++cnt;
  }
  cout << cnt << '\n';
  return 0;
}
