#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#define N 100001
#define WHITE 0
#define GRAY 1

using namespace std;

int color[N];
vector<int> G[N];
list<int> L;
stack<int> S;

void dfs (int u, int V) {
  color[u] = GRAY;
  S.push(u);

  while (S.size()) {
    bool flag = false;

    for (int i = 0; i < G[S.top()].size(); i++) {
      int v = G[S.top()][i];

      if (color[v] == WHITE) {
        S.push(v);
        color[v] = GRAY;
        flag = true;
        break;
      }
    }

    if (!flag) {
      L.push_front(S.top());
      S.pop();
    }
  }
}

void dfs_init (int V) {
  for (int i = 0; i < V; i++) {
    if (color[i] == WHITE) {
      dfs(i, V);
    }
  }
}

int main () {
  int V, E, u, v;
  
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    G[u].push_back(v);
  }

  dfs_init(V);

  for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << endl;

  return 0;
}
