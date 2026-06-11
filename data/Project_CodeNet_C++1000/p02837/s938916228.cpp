#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int g[15][15];

int main(void) {
  int N;
  cin >> N;
  rep(i, N) {
    rep(j, N) {
      g[i][j] = -1;
    }
  }
  rep(i, N) {
    int m;
    cin >> m;
    rep(j, m) {
      int x, y;
      cin >> x >> y;
      --x;
      g[i][x] = y;
      // i番目の人はx番目の人から見て正直者か？
    }
  }

  int ans = 0;
  rep(i, 1<<N) {
    // すべての正直者パターンを作る
    vector<int> d(N);
    rep(j, N) {
      if (i >> j & 1) {
        d[j] = 1;
      }
    }

    bool ok = true;
    rep(j, N) {
      if (d[j]) {
        // jさんが正直者ならば、証言が成立するか？
        rep(k, N) {
          if (g[j][k] == -1) {
            // kからの証言はない
            continue;
          }
          if (g[j][k] != d[k]) {
            ok = false;
          }
        }
      }
    }
    if (ok) {
      ans = max(ans, __builtin_popcount(i));
    }
  }

  cout << ans << endl;
  
  return 0;
}