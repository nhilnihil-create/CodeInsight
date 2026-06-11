#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n =  s.size();
  vector<ll> a(n+1,0);
  rep(i,n) {
    if(s.at(i)=='<') {
      a[i+1] = a[i]+1;
    }
  }
  for(int i = n; i > 0; --i) {
    if(s.at(i-1)=='>') {
      a[i-1] = max(a[i-1], a[i]+1);
    }
  }
  ll ans = 0;
  rep(i,n+1) ans += a[i];
  cout << ans << endl;
}
