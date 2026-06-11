#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>

using namespace std;
const int MAXV = 10000;
const int MAXE = 100000;

int indeg[MAXV];
bool used[MAXV];
vector<int> G[MAXV];
vector<int> out;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  used[start] = true;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    out.push_back(cur);
    for (int i = 0; i < G[cur].size(); ++i) {
      int v = G[cur][i];
      indeg[v]--;
      if (indeg[v] == 0 && !used[v]) {
	used[v] = true;
	q.push(v);
      }
    }
  }  
}

void topological_sort(int n) {
  for (int i = 0; i < n; ++i) indeg[i] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < G[i].size(); ++j) {
      int v = G[i][j];
      indeg[v]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (indeg[i] == 0 && !used[i]) bfs(i);
  }
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);
  for (int i = 0; i < e; ++i) {
    int s, t;
    scanf("%d %d", &s, &t);
    G[s].push_back(t);
  }

  for (int i = 0; i < v; ++i) used[i] = false;
  topological_sort(v);
  for (size_t i = 0; i < out.size(); ++i) {
    printf("%d\n", out[i]);
  }
  return 0;
}

