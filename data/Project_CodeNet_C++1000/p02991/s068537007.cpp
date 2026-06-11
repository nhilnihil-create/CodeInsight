#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int solve(auto& G, auto S, auto T) {
  using Memo = pair<int, int>;
  set<Memo> d;

  using Node = tuple<int, int, int>;
  priority_queue<Node, vector<Node>, greater<Node>> q;

  q.emplace(0, 0, S);

  while(!q.empty()) {
    int cost, step, u;
    tie(cost, step, u) = q.top();
    q.pop();

    if(u == T && step == 0) return cost;

    Memo memo = {step, u};
    if(d.count(memo)) continue;
    d.emplace(memo);

    for(auto v: G[u]) {
      if(step < 2) q.emplace(cost, step + 1, v);
      else         q.emplace(cost + 1, 0, v);
    }
  }

  return -1;
}

int main() {
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for(auto i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].emplace_back(v);
  }

  int S, T;
  cin >> S >> T;
  --S; --T;

  cout << solve(G, S, T) << endl;
}
