#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll k,x;
  cin >> k >> x;
  
  for(ll i=x-(k-1); i<x; i++)
    cout << i << " ";
  for(ll i=x; i<x+k; i++)
    cout << i << " ";
  cout << endl;
}