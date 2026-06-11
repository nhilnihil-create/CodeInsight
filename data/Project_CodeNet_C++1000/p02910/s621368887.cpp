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
  ll n = s.size();
  
  rep(i, n){
    if(i%2 == 0){//奇数番目
      if(s.at(i) != 'R' && s.at(i) != 'U' && s.at(i) != 'D'){
        cout << "No" << endl;
        return 0;
      }
    }
    if(i%2 == 1){//偶数番目
      if(s.at(i) != 'L' && s.at(i) != 'U' && s.at(i) != 'D'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}