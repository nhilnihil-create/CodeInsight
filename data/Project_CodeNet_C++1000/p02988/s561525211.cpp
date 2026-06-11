#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n; cin >> n;
  vector<ll> p(n);
  rep(i, n)
    cin >> p[i];
  
  ll cnt = 0;
  for(ll i=1; i<n-1; i++){
    if(p[i-1]<p[i] && p[i+1]>p[i])
      cnt++;
    if(p[i-1]>p[i] && p[i+1]<p[i])
      cnt++;
  }
  cout << cnt << endl;
}