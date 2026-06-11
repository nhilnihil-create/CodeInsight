#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  vector<int> l(n + 1), r(n + 1);
  rep(i, 0, n) l[i] = s[i] == 'L';
  rep(i, 0, n) r[i] = s[i] == 'R';
  rep(i, 0, n) if (s[i] == 'R') r[i + 1] += r[i];

  rrep(i, 1, n) if (s[i] == 'L') l[i - 1] += l[i];

  vector<int> ans(n);
  if (s[0] == 'L') ans[0] = l[0];
  rep(i, 0, n - 1) if (s[i] == 'R' && s[i + 1] == 'L') {
    ans[i] = (r[i] + 1) / 2 + l[i + 1] / 2;
    ans[i + 1] = r[i] / 2 + (l[i + 1] + 1) / 2;
  }
  if (s[n - 1] == 'R') ans[n - 1] = r[n];
  rep(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
  return 0;
}