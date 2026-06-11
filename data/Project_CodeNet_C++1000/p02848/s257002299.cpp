#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  vector<char> v = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  ll k;
  cin >> k;
  string s;
  cin >> s;
  
  ll n = s.size();
  string ans;
  
  rep(i, n){
    rep(j, 26){
      if(s.at(i) == v.at(j))
        ans.push_back(v.at((j+k)%26));
    }
  }
  cout << ans << endl;
}