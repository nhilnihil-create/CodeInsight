#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <math.h>

#define rep(i, n) for (auto i = 0; i < (n); i++)
#define MOD 1e9 + 7
typedef long long ll;

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  char c[h][w];
  rep(i, h) rep(j, w) cin >> c[i][j];
  int ans = 0;
  for (int rmask = 0; rmask < (1 << h) - 1; rmask++) {
    for (int cmask = 0; cmask < (1 << w) - 1; cmask++) {
      int black = 0;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (((rmask >> i) & 1) == 0 && ((cmask >> j) & 1) == 0 && c[i][j] == '#')
            black++;
        }
      }
      if (black == k) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

