#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<P> graph[N+1];
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    graph[a].emplace_back(b, i);
    graph[b].emplace_back(a, i);
  }
  int root = 1;
  vector<int> parent(N+1, -1);
  vector<int> order;
  vector<int> color(N-1);
  vector<P> stk;
  stk.emplace_back(root, -1);
  int maxNum = 1;
  while (!stk.empty()) {
    auto p = stk.back();
    int cur = p.first;
    int colP = p.second;  // 親との辺をcolPとする
    stk.pop_back();
    order.push_back(cur);
    int col = 1;
    for (auto pa : graph[cur]) {
      int next = pa.first;
      if (next == parent[cur]) continue;
      if (col == colP) ++col;
      parent[next] = cur;
      color[pa.second] = col;
      stk.emplace_back(next, col);
      if (col > maxNum) maxNum = col;
      ++col;
    }
  }
  cout << maxNum << '\n';
  for (int i = 0; i < N-1; i++) {
    cout << color[i] << '\n';
  }
  return 0;
}