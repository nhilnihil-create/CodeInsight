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
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  long k;
  string s;
  cin >> s >> k;
  int n = (int)s.size();
  vector<pair<char, int>> a;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j + 1 < n && s[j + 1] == s[i]) ++j;
    a.emplace_back(s[i], j - i + 1);
    i = j;
  }
  long ans = 0, mae = 0, naka = 0, ushiro = 0;

  int m = (int)a.size();
  if (m == 1) {
    ans = a[0].second * k / 2;
  } else if (a[0].first == a[m - 1].first) {
    for (int i = 1; i < m - 1; ++i) ans += a[i].second / 2 * k;
    ans += a[0].second / 2;
    ans += a[m - 1].second / 2;
    ans += (a[0].second + a[m - 1].second) / 2 * (k - 1);
  } else {
    for (auto p : a) ans += p.second / 2 * k;
  }
  cout << ans << endl;
}