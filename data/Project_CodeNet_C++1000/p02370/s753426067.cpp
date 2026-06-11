#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

class TopologicalSort {
public:
  int n;
  vector< vector<int> > G;
  vector<bool> used;
  vector<int> indeg;
  vector<int> out;

  TopologicalSort(int _n): n(_n), G(n), used(n), indeg(n), out(0) {}

  void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      out.push_back(cur);
      for (int v: G[cur]) {
	indeg[v]--;
	if (indeg[v] == 0 && !used[v]) {
	  used[v] = true;
	  q.push(v);
	}
      }
    }
  }
  
  void add_edge(int from, int to) {
    G[from].push_back(to);
  }
  
  vector<int> build() {
    fill(indeg.begin(), indeg.end(), 0);
    fill(used.begin(), used.end(), 0);
    for (int i = 0; i < n; ++i)
      for (int v: G[i]) indeg[v]++;

    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 0 && !used[i]) bfs(i);
    }
    return out;
  }
};

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  TopologicalSort tp = TopologicalSort(v);
  for (int i = 0; i < e; ++i) {
    int s, t;
    scanf("%d %d", &s, &t);
    tp.add_edge(s, t);
  }
  vector<int> ans = tp.build();
  for (size_t i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

