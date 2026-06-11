#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i, n)
    cin >> v.at(i);
  
  ll ans = 0;
  rep(i, n){
    for(ll j=i+1; j<n; j++)
      ans += v.at(i)*v.at(j);
  }
  
  cout << ans << endl;
}