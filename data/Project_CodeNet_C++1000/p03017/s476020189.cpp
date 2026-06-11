#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s; cin >> s;
  string ans = "Yes";
  bool space = false;
  for (int i = a; i <= max(c,d); i++) {
    if (a < i && i <= c) {
      if (s[i] == '#' && s[i+1] == '#') {ans = "No"; break;}
    }
    if (b <= i && i <= d) {
      if (s[i] == '#' && s[i+1] == '#') {ans = "No"; break;}
      if (s[i] == '.' && s[i-1] == '.' && s[i+1] == '.') space = true;
    }
  }
  if (c > d && !space) ans = "No";
  cout << ans << endl;
  return 0;
}