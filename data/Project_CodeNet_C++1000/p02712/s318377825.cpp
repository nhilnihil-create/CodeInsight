#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  cin >> n;
  
  vector<ll> vec(n+1);
  rep(i, n+1)
    vec.at(i) = i;
  
  ll ans = 0;
  
  rep(i, n+1){
    if(vec.at(i) % 3 != 0 && vec.at(i) % 5 != 0)
      ans += vec.at(i);
  }
  cout << ans << endl;
}