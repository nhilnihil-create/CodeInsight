#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i,m) cin >> s[i] >> c[i], --s[i];
  string ans = "-1";
  rep(i,1000) {
    string si =  to_string(i);
    if ((int)si.size() != n) continue;
    bool flag = true;
    rep(j,m) {
      if (si[s[j]] != (char)(c[j] + '0')) flag = false;
    }
    if (flag) { ans = si; break; }
  }
  cout << ans << endl;
  return 0;
}