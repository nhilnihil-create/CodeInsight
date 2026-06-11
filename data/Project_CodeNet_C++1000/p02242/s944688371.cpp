#include <iostream>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_N 101
#define INF 100000000
using namespace std;

int m[MAX_N][MAX_N];
int d[MAX_N];
int color[MAX_N];

void dijkstra(int s, int n) {
  for (int i = 0; i < n; i++) {
    d[i] = INF;
    color[i] = WHITE;
  }

  d[s] = 0;
  color[s] = GRAY;

  while (true) {
    int mincost = INF;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (color[i] != BLACK && d[i] < mincost) {
	mincost = d[i];
	u = i;
      }
    }
    
    if (mincost == INF) break;
    
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && m[u][v] != INF) {
	if (d[u] + m[u][v] < d[v]) {
	  d[v] = d[u] + m[u][v];
	  color[v] = GRAY;
	}
      }
    }
  }
}

void init(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = INF;
    }
  }
}

int main() {
  int n;
  cin >> n;

  init(n);
  
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int i = 0; i < k; i++) {
      int v, c;
      cin >> v >> c;
      m[u][v] = c;
    }
  }

  dijkstra(0, n);

  for (int i = 0; i < n; i++) {
    cout << i << " " << d[i] << endl;
  }

  return 0;
}