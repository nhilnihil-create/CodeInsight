#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0;i<(int)n;++i)

int main(){
  ll n,k;cin >> n >> k;
  ll r,s,p;cin >> s >> p >> r;
  map<char,ll> m;
  m['s'] = s;
  m['p'] = p;
  m['r'] = r;
  string t;cin >> t;
  vector<bool> b(n);

  ll ans = 0;
  rep(i,n){
    if( i-k >= 0 ){
      if( t.at(i-k) == t.at(i) && b.at(i-k) ){
        continue;
      }
    }
    ans += m[t.at(i)];
    b.at(i) = true;
  }
  

  cout << ans << endl;
  return 0;
}