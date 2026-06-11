#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n; string s;
  cin >> n >> s;
  if(n%2 == 1){
    cout << "No" << endl;
    return 0;
  }
  
  string t,u;
  rep(i, n/2)
    t.push_back(s.at(i));
  for(ll i=n/2; i<n; i++)
    u.push_back(s.at(i));
  
  if(t == u)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}