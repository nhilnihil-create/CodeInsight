#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int L = 100005;

string s, t;

int a[L][26];

int main() {
  cin >> s >> t;
  rep(i, s.size()) rep(j, 26) a[i][j] = -1;
  rep(j, 26) {
    char c = 'a' + j;
    vector<int> cp;
    rep(i, s.size()) if (s[i] == c) cp.push_back(i);
    if (cp.size() == 0) continue;
    cp.push_back(cp[0]);
    int cpi = 0;
    rep(i, s.size()) {
      if (i == cp[cpi]) cpi++;
      a[i][j] = cp[cpi];
    }
  }
  // rep(i, s.size()) {
  //   rep(j, 26) printf("%d ", a[i][j]);
  //   printf("\n");
  // }
  int si = s.size()-1;
  ll ans = 0;
  rep(ti, t.size()) {
    int nsi = a[si][t[ti] - 'a'];
    if (nsi == -1) {
      ans = -1;
      break;
    }
    ans += nsi - si;
    if (nsi <= si) ans += s.size();
    si = nsi;
    // printf("ans = %lld\n", ans);
  }
  cout << ans << endl;
  return 0;
}