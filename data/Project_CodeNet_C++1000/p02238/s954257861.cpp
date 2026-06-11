#include <iostream>
#define MAX_N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int G[MAX_N][MAX_N];
int status[MAX_N];
int d[MAX_N];
int f[MAX_N];
int time_count, n;

void dfs_visit(int v) {
  d[v] = ++time_count;
  status[v] = GRAY;
  for (int i = 1; i <= n; i++) {
    if (G[v][i] && status[i] == WHITE) dfs_visit(i);
  }

  f[v] = ++time_count;
  status[v] = BLACK;
}

void dfs() {
  for (int i = 0; i < n; i++) {
    status[i] = WHITE;
  }

  time_count = 0;
  int i;
  for (i = 1; i <= n; i++) {
    if (status[i] == WHITE) {
      dfs_visit(i);
    }
  }
}

void init() {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      G[i][j] = 0;
    }
  }
}

int main() {
  init();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      G[u][v] = 1;
    }
  }

  dfs();

  for (int i = 1; i <= n; i++) {
    cout << i << ' ' << d[i] << ' ' << f[i] << endl;
  }
}