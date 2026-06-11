#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  string s;
  cin >> s;
  ll cnt = 0;
  rep(i, s.size()/2){
    if(s.at(i) != s.at(s.size()-i-1))
      cnt++;
  }
  cout << cnt << endl;
}