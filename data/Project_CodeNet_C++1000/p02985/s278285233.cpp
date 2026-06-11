#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;

void dfs(const graph &to, vector<int64_t> &color, int v, int p, int k) {
  int c = k;
  if (v != 0) c--;
  for (int x : to.at(v)) {
    if (x == p) continue;
    c--;
    color.at(x) = c;
    dfs(to, color, x, v, k);
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  graph to(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to.at(a).push_back(b);
    to.at(b).push_back(a);
  }
  vector<int64_t> color(n);
  color.at(0) = k;
  dfs(to, color, 0, -1, k);
  int64_t ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= color.at(i);
    ans %= 1000000007;
  }
  cout << ans << endl;
}
