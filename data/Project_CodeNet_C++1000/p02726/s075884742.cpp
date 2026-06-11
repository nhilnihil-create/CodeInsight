#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

vector<int> g[2000];
int re[2000];
vector<int> ds;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  repi(n - 1) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  g[x - 1].push_back(y - 1);
  g[y - 1].push_back(x - 1);
  repi(n) {
    ds = vector<int>(n, -1);
    ds[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      itr(g[p]) {
        if (ds[v] >= 0) continue;
        ds[v] = ds[p] + 1;
        q.push(v);
      }
    }
    repj(n)++ re[ds[j]];
  }
  rep(i, 1, n) cout << re[i] / 2 << endl;
}
