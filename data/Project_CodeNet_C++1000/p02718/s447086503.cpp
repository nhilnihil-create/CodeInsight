#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int s = accumulate(a.begin(), a.end(), 0);

  int cnt = 0;
  rep(i, 0, n) {
    if (a[i] * m * 4 < s) continue;
    ++cnt;
  }

  if (cnt >= m)
    cout << "Yes";
  else
    cout << "No";

  return 0;
}
