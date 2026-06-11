#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
  
  string s; ll q;
  cin >> s >> q;
  string u;
  
  rep(i,q) {
    ll t;
    cin >> t;
    if (t==1)  swap(s,u);
    if (t==2) {
      ll f; char c;
      cin >> f >> c;
      if (f==1) u += c;
      if (f==2) s += c;
    }
  }
  
  reverse(u.begin(), u.end());
  u += s;
  cout << u << endl;
}