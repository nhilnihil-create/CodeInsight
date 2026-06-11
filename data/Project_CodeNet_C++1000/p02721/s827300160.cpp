#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N, K, C;
  cin >> N >> K >> C;
  string s;
  cin >> s;

  vector<int> l(K + 1), r(K + 1);
  {
    l[0] = -C - 1;
    int j = 0;
    rep(i, K) {
      while (s[j] == 'x' || j <= l[i] + C) {
        j++;
      }
      l[i + 1] = j;
    }
  }
  {
    r[K] = N + C;
    int j = N - 1;
    rrep(i, K) {
      while (s[j] == 'x' || j >= r[i + 1] - C) {
        j--;
      }
      r[i] = j;
    }
  }

  rep(i, K) {
    if (l[i + 1] == r[i]) {
      cout << r[i] + 1 << "\n";
    }
  }
  return 0;
}