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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = 0; i < k; ++i) ans += p[i];
  cout << ans << endl;
}
