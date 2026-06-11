#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

// dfs
// p は親
void dfs(int i, int p, vector<vector<int>> &graph, vector<ll> &sum) {
  int x = sum.at(i);
  vector<int> children = graph.at(i);
  for (int child : children) {
    if (child == p) {
      continue;
    }
    sum.at(child) += x;
    dfs(child, i, graph, sum);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> graph(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  vector<P> px(q);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    px.at(i) = make_pair(p, x);
  }
  // 頂点pにのみ追加
  vector<ll> sum(n, 0);
  for (auto v : px) {
    int p = v.first;
    int x = v.second;
    sum.at(p) += x;
  }
  // 最後にまとめて部分木にも追加
  dfs(0, -1, graph, sum);
  // 出力
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << " ";
    }
    int x = sum.at(i);
    cout << x;
  }
  cout << endl;
  return 0;
}
