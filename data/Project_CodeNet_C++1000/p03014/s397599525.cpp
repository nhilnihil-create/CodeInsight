#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int H, W;
string S[2020];
int up[2020][2020], down[2020][2020], l[2020][2020], r[2020][2020];

int main() {
  cin >> H >> W;
  rep(i, 0, H) { cin >> S[i]; }

  for (int j = 0; j < W; ++j) {
    for (int i = 1; i < H; ++i) {
      if (S[i - 1][j] == '.') {
        up[i][j] = up[i - 1][j] + 1;
      } else {
        up[i][j] = 0;
      }
    }

    for (int i = H - 2; i >= 0; --i) {
      if (S[i + 1][j] == '.') {
        down[i][j] = down[i + 1][j] + 1;
      } else {
        down[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 1; j < W; ++j) {
      if (S[i][j - 1] == '.') {
        l[i][j] = l[i][j - 1] + 1;
      } else {
        l[i][j] = 0;
      }
    }

    for (int j = W - 2; j >= 0; --j) {
      if (S[i][j + 1] == '.') {
        r[i][j] = r[i][j + 1] + 1;
      } else {
        r[i][j] = 0;
      }
    }
  }

  int ans = 0;
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (S[i][j] == '#') continue;

      chmax(ans, up[i][j] + down[i][j] + l[i][j] + r[i][j] + 1);
    }
  }

  cout << ans;
}
