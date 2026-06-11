#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int V, E; cin >> V >> E;

  vector<vector<bool>> edge(V, vector<bool>(V, false));
  vector<int> in(V, 0);

  queue<int> no_incoming_edge;
  rep(i, E) {
    int s, t;
    cin >> s >> t;
    edge[s][t] = true;
    ++in[t];
  }
  rep(i, V) {
    if (in[i] == 0)
      no_incoming_edge.push(i);
  }
  vector<int> ans;
  while (!no_incoming_edge.empty()) {
    int p = no_incoming_edge.front(); no_incoming_edge.pop();
    ans.push_back(p);
    rep(to, V) {
      if (edge[p][to] == 1) {
        --in[to];
        if (in[to] == 0)
          no_incoming_edge.push(to);
      }
    }
  }
  rep(i, V)
    out(ans[i]);

  return 0;
}
