#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 100100100;

int main() {
  int h, n;
  cin >> h >> n;
  int m = 1e8 + 10;
  vector<int> hs(m, INF);
  vector<P> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab[i] = P(a, b);
  }
  hs[0] = 0;
  for (int i = 0; i <= h; i++) {
    rep(j, n) {
      int a = ab[j].first;
      int b = ab[j].second;
      hs[i + a] = min(hs[i + a], hs[i] + b);
    }
  }

  int ans = INF;
  for (int i = h; i < m; i++) {
    ans = min(hs[i], ans);
  }
  cout << ans << endl;
  return 0;
}
