#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n; cin >> n;
  vector<ll>v(n);
  ll h = 0;
  rep(i,n){
    cin >> v.at(i);
    h += v.at(i)*v.at(i);
  }
  ll sum = 0;
  rep(i,n){
    rep(j,n){
      sum += v.at(i)*v.at(j);
    }
  }
  cout << (sum-h)/2 << endl;
  
  
  return 0;
}