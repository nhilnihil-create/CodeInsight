#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, a, b;
vector<ii> e[N];
int res[N];
int ans;

void dfs(int par, int u, int c) {
  int i = 1;
  for (auto p : e[u]) {
    int v = p.first, resno = p.second;
    if (v == par) continue;
    if (c == i) ++i;
    res[resno] = i;
    ans = max(ans, i);
    dfs(u, v, i++);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    e[a].push_back(ii(b, i));
    e[b].push_back(ii(a, i));
  }

  dfs(0, 1, 0);
  cout << ans << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}
