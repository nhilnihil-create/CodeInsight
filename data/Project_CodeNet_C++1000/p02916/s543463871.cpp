#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n; cin >> n;
  vector<ll> a(n),b(n),c(n-1);
  rep(i, n)
    cin >> a.at(i);
  rep(i, n)
    cin >> b.at(i);
  rep(i, n-1)
    cin >> c.at(i);
  
  ll ans = 0;
  rep(i, n){
    ans += b.at(a.at(i)-1);
    if(i<n-1){
      if(a.at(i)+1 == a.at(i+1))
      ans += c.at(a.at(i)-1);
    }
  }
  cout << ans << endl;
}