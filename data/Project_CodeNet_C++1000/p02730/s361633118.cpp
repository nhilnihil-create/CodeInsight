#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  string s;
  cin >> s;
  ll n = s.size();
  bool ans = true;
  
  rep(i, n){
    if(s.at(i) != s.at(n-1-i))
      ans = false;
  }
//  cout << ans << endl;
  rep(i, (n-1)/2){
    if(s.at(i) != s.at((n-1)/2 -1-i))
      ans = false;
  }
//  cout << ans << endl;
  for(ll i=(n+3)/2; i<n; i++){ 
    if(s.at(i) != s.at(n-1-i))
      ans = false;
  }
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}