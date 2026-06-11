#include <atcoder/scc>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
int m, n, a, b, city[100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  scc_graph g(n);

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    g.add_edge(a - 1, b - 1);
    g.add_edge(b - 1, a - 1);
  }

  auto s = g.scc();
  cout << s.size() - 1;

  //  for (auto x : s) {
  //  cout << "\n";
  // for (auto q : x) {
  // cout << q << " ";
  //}
  //}
  return 0;
}
