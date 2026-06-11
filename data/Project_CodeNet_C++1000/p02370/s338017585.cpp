#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repR(i, n) for(int i = (n) - 1; i > -1; i--)
#define rep1(i, n) for(int i = 1; i < (int)(n + 1); i++)
#define rep1R(i, n) for(int i = (n); i > 0; i--)
#define ll long long
using namespace std;

const int MAX = 10000;

enum Color {
  WHITE = 0,
  GRAY = 1,
  BLACK = 2,
};

vector<int> adj[MAX + 10];
Color color[MAX + 10];
int indeg[MAX + 10] = {};
list<int> out;

void bfs(int s) {
  queue<int> Q;
  Q.push(s);
  color[s] = GRAY;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    out.push_back(u);

    rep(i, adj[u].size()) {
      int v = adj[u][i];
      --indeg[v];
      if (indeg[v] == 0 && color[v] == WHITE) {
        color[v] = GRAY;
        Q.push(v);
      }
    }
  }
}

void topologicalSort(int V) {
  rep(i, V) color[i] = WHITE;

  rep(u, V) {
    if (indeg[u] == 0 && color[u] == WHITE) bfs(u);
  }
}

int main() {
  int V, E;
  cin >> V >> E;
  rep(i, E) {
    int s, t;
    cin >> s >> t;
    adj[s].push_back(t);
    ++indeg[t];
  }
  topologicalSort(V);
  for (auto i : out) cout << i << endl;
  return 0;
}

