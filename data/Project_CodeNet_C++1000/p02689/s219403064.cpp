#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <set>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
int m;

vi a;
vector<set<int>> g;

void input() {
  a.clear();
  g.clear();

  cin >> n >> m;

  a.resize(n);
  g.resize(n);

  for (auto&& i : a)
    cin >> i;

  for (int i = 0; i < m; ++i) {
    int u;
    int v;
    cin >> u >> v;

    --u;
    --v;

    g[u].insert(v);
    g[v].insert(u);
  }
}

void solve() {
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    bool ok = true;

    for (auto&& j : g[i]) {
      if (a[j] >= a[i]) {
        ok = false;

        break;
      }
    }

    ans += ok;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
