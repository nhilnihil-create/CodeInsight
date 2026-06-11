#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  auto dist = [&](int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
  };

  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  double len = 0;
  int cnt = 0;
  do {
    for (int i = 0; i < n - 1; ++i) {
      len += dist(p[i], p[i + 1]);
    }
    cnt++;
  } while (next_permutation(p.begin(), p.end()));
  double ans = len / cnt;
  printf("%.10f\n", ans);
}
