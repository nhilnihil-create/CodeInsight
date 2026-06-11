#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 999999999999999;

int main(){
  string s,t;cin >> s >> t;
  ll ans = 0;
  rep(i,s.size()){
    if( s.at(i) != t.at(i) ) ++ans;
  }
  cout << ans << endl;
  return 0;
}