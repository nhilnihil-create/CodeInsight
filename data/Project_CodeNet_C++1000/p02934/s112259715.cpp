#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n; cin >> n;
  vector<double> v(n);
  rep(i, n)
    cin >> v.at(i);
  
  vector<double> w(n);
  rep(i, n)
    w.at(i) = 1 / v.at(i);
  
  double sum = 0;
  rep(i, n){
    sum += w.at(i);
   // cout << w.at(i);
  }
  cout << 1/sum << endl;
}