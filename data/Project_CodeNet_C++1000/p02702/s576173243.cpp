#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, m, n) for (int i = m; i < n; i++)
using str = string;
using vi = vector<int>;

int d[2019];
int d2[2019];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);

  vi a(200010);
  str s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  rep(i, n) a[i] = s[i] - '0';
  d2[a[0]]++;
  REP(i, 1, n) {
    d[a[i]]++;
    rep(j, 2019) { d[(10 * j + a[i]) % 2019] += d2[j]; }
    ans += d[0];
    rep(j, 2019) {
      d2[j] = d[j];
      d[j] = 0;
    }
  }
  cout << ans << endl;
}
