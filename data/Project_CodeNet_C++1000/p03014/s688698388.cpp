#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int h, w;
  cin >> h >> w;
  char s[h][w];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> s[i][j];
    }
  }
  ll l[h][w], r[h][w], u[h][w], d[h][w];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (j == 0) {
        l[i][j] = (s[i][j] == '#' ? 0 : 1);
      } else {
        l[i][j] = (s[i][j] == '#' ? 0 : l[i][j - 1] + 1);
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = w - 1; j >= 0; --j) {
      if (j == w - 1) {
        r[i][j] = (s[i][j] == '#' ? 0 : 1);
      } else {
        r[i][j] = (s[i][j] == '#' ? 0 : r[i][j + 1] + 1);
      }
    }
  }
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (j == 0) {
        u[j][i] = (s[j][i] == '#' ? 0 : 1);
      } else {
        u[j][i] = (s[j][i] == '#' ? 0 : u[j - 1][i] + 1);
      }
    }
  }
  for (int i = 0; i < w; ++i) {
    for (int j = h - 1; j >= 0; --j) {
      if (j == h - 1) {
        d[j][i] = (s[j][i] == '#' ? 0 : 1);
      } else {
        d[j][i] = (s[j][i] == '#' ? 0 : d[j + 1][i] + 1);
      }
    }
  }
  ll ans = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      ans = max(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
    }
  }
  cout << ans << endl;
  return 0;
}