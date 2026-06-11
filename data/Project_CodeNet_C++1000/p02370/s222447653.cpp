/*
 * Given a DAG G, print the order of vertices after the topological sort.
 * Output
 * Print the vertices numbers in order. Print a number in a line.
 * If there are multiple possible solutions, print any one of them (the solution
 * is judged by a special validator).
 *
 * Constraints
 * 1≤|V|≤10,000
 * 0≤|E|≤100,000
 * There are no parallel edges in G
 * There are no self loops in G
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define MAXN 10000
#define MAXM 100000

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  struct {
    int to, next;
  } E[MAXM];
  vector<int> LE(MAXN, -1);

  int n, m;
  cin >> n >> m;
  for (int i = 0, s, t; i < m; ++i) {
    cin >> s >> t;
    E[i] = {t, LE[s]};
    LE[s] = i;
  }

  bool visited[MAXN]{0};

  struct data {
    int id;
    bool post;
  };
  stack<data> dfs;
  stack<int> topo;
  for (int i = 0; i < n; ++i) {
    if (visited[i])
      continue;
    dfs.push({i, 0});
    while (!dfs.empty()) {
      data d = dfs.top();
      dfs.pop();
      if (visited[d.id] && !d.post)
        continue;
      if (visited[d.id] && d.post) {
        topo.push(d.id);
      } else {
        visited[d.id] = true;
        dfs.push({d.id, 1});
        for (int e = LE[d.id]; e != -1; e = E[e].next)
          if (!visited[E[e].to])
            dfs.push({E[e].to, 0});
      }
    }
  }

  while (!topo.empty()) {
    cout << topo.top() << endl;
    topo.pop();
  }
}
