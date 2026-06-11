#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr int INF = 0x3f3f3f3f;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  // プラスグループ、マイナスグループ
  // +: 最初+, マイナスを引いていく
  // -: 最初-, プラスを引いていく

  // 全部+, 全部-の時は

  // 0は+扱い
  int min_plus = INF;
  int min_minus = -INF;
  int mpi, mmi;
  rep(i, 0, n) {
    if (a[i] < 0) {
      if (a[i] > min_minus) {
        min_minus = a[i];
        mmi = i;
      }
    } else {
      if (a[i] < min_plus) {
        min_plus = a[i];
        mpi = i;
      }
    }
  }

  int ans = 0;
  vector<pair<int, int>> op;
  if (min_minus == -INF) {
    rep(i, 0, n - 1) {
      if (i == mpi) continue;
      op.emplace_back(a[mpi], a[i]);
      a[mpi] -= a[i];
    }
    op.emplace_back(a[n - 1], a[mpi]);
    a[n - 1] -= a[mpi];
    cout << a[n - 1] << '\n';
  } else if (min_plus == INF) {
    op.emplace_back(a[mmi], a[n - 1]);
    a[mmi] -= a[n - 1];
    rep(i, 0, n - 1) {
      if (i == mmi) continue;
      op.emplace_back(a[mmi], a[i]);
      a[mmi] -= a[i];
    }
    cout << a[mmi] << '\n';
  } else {
    rep(i, 0, n) {
      if (i == mpi || i == mmi) continue;
      if (a[i] < 0) {
        op.emplace_back(a[mpi], a[i]);
        a[mpi] -= a[i];
      } else {
        op.emplace_back(a[mmi], a[i]);
        a[mmi] -= a[i];
      }
    }
    op.emplace_back(a[mpi], a[mmi]);
    a[mpi] -= a[mmi];
    cout << a[mpi] << '\n';
  }
  rep(i, 0, op.size()) cout << op[i].first << " " << op[i].second << '\n';
}