#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  string s; cin >> s;
  ll n = s.size();
  ll ans = 0;
  string s2;
  rep(i,n/2){
    s2 += s.at(n-i-1);
  }
  rep(i,n/2){
    if(s.at(i)!=s2.at(i)) ans++;
  }
  cout << ans << endl;
  
  return 0;
}