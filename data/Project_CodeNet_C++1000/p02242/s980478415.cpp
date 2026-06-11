#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_VERTEX 100
#define INF 1000000

int cost[MAX_VERTEX][MAX_VERTEX];
int d[MAX_VERTEX];
bool used[MAX_VERTEX];

int main() {
  int vertex_num;
  cin >> vertex_num;

  for(int i = 0; i < vertex_num; i++) {
    d[i] = INF;
    used[i] = false;
    for(int j = 0; j < vertex_num; j++) {
      cost[i][j] = INF;
    }
  }

  for (int i = 0; i < vertex_num; i++) {
    int vertex, out;
    cin >> vertex >> out;
    for(int j = 0; j < out; j++) {
      int to, c;
      cin >> to >> c;
      cost[vertex][to] = c;
    }
  }

  d[0] = 0;
  while(true) {
    int vertex = -1;
    for(int u = 0; u < vertex_num; u++) {
      if(!used[u] && (vertex == -1 || d[u] < d[vertex])) {
        vertex = u;
      }
    }

    if (vertex == -1) break;

    used[vertex] = true;

    for(int u = 0; u < vertex_num; u++) {
      d[u] = min(d[u], d[vertex] + cost[vertex][u]);
    }
  }

  for(int i = 0; i < vertex_num; i++) {
    cout << i << " " << d[i] << endl;
  }

  return 0;
}