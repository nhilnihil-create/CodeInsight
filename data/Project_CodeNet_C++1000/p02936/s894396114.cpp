#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

vector<int> g[200000];
vector<ll> cnt(200000);

void dfs(int v, int p, int c) {
  cnt[v] += c;
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs(u, v, cnt[v]);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> p(q), x(q);
  for (int i = 0; i < q; ++i) {
    cin >> p[i] >> x[i];
    p[i]--;
    cnt[p[i]] += x[i];
  }
  dfs(0, -1, 0);
  for (int i = 0; i < n; ++i) {
    cout << cnt[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}