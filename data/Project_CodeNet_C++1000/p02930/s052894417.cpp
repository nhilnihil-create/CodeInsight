#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> ans(n, vector<int>(n, -1));

  vector<int> group(n, 0);
  for (int level = 1;; level++) {
    vector<int> grcnt(n*3), sgcnt(n*3);
    for (int i = 0; i < n; i++) { grcnt[group[i]]++; }
    for (int i = 0; i < n; i++) {
      int thres = grcnt[group[i]] / 2;
      if (sgcnt[group[i]]++ < thres) {
        group[i] = group[i] * 2 + 1;
      } else {
        group[i] = group[i] * 2;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (ans[i][j] > 0) continue;
        if (group[i] != group[j]) {
          ans[i][j] = level;
          ans[j][i] = level;
          cnt++;
        }
      }
    }
    if (cnt == 0) break;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      printf("%d%c", ans[i][j], " \n"[(j + 1 == n) ? 1 : 0]);
    }
  }
  return 0;
}
