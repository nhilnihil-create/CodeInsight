#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  set<string> S;
  int ans = 0;
  string sb, si;
  rep(i,s.size()) {
    si += s[i];
    if (sb != si) {
      sb = si;
      si.clear();
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}