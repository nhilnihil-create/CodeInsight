#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, m, used[N], ans;
vector<int> g[N];

void dfs(int x) {
  used[x] = 1;
  for (int i: g[x]) {
    if (!used[i]) {
      dfs(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      ++ans;
      dfs(i);
    }
  }
  cout << ans - 1 << '\n';
}
