#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_V 101
#define INF 10000000
using namespace std;

bool edge[MAX_V][MAX_V];
int dist[MAX_V];

void bfs(int start, int n) {
  queue<int> que;
  que.push(start);
  dist[start] = 0;
  int current;
  while (!que.empty()) {
    current = que.front();
    que.pop();
    for (int i = 1; i <= n; i++) {
      if (edge[current][i] && dist[i] == INF) {
	dist[i] = dist[current] + 1;
	que.push(i);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      edge[i][j] = false;
    }
  }
  for (int j = 0; j < n; j++) {
    int u, k;
    cin >> u >> k;
    for (int i = 0; i < k; i++) {
      int v;
      cin >> v;
      edge[u][v] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }

  bfs(1, n);

  for (int i = 1; i <= n; i++) {
    cout << i << ' ';
    if (dist[i] == INF) cout << -1 << endl;
    else cout << dist[i] << endl;
  }
}