#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i, h) cin >> c[i];

  int ans = 0;
  int cnt;
  rep(i, 1 << h) {
    rep(j, 1 << w) {
      cnt = 0;
      rep(s, h) {
        rep(t, w) {
          if (i & (1 << s)) continue;
          if (j & (1 << t)) continue;
          if (c[s][t] == '#') ++cnt;
        }
      }
      if (cnt == k) ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}