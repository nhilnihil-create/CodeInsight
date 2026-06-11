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

int n, m, q;
vector<int> a, b, c, d;
int ans;

void dfs(vector<int> A) {
  if (A.size() == n + 1) {
    int now = 0;
    for (int i = 0; i < q; ++i) {
      if (A[b[i]] - A[a[i]] == c[i]) now += d[i];
    }
    ans = max(ans, now);
    return;
  }

  A.push_back(A.back());
  while (A.back() <= m) {
    dfs(A);
    A.back()++;
  }
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);

  for (int i = 0; i < q; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
  dfs(vector<int>(1, 1));
  cout << ans << endl;
}
