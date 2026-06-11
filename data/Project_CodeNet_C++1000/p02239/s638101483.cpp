#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef complex<double> P;

int main() {
  int n; cin >> n;
  int adj[n][n] = {};

  for (int i = 0; i < n; i++) {
    int u, k; cin >> u >> k;
    
    for (int j = 0; j < k; j++) {
      int v; cin >> v;
      adj[u-1][v-1] = 1;
    }
  }

  int d[n];
  fill(d, d+n, -1);

  queue<int> que;
  que.push(0);
  d[0] = 0;

  while(!que.empty()) {
    int v = que.front(); que.pop();

    for (int i = 0; i < n; i++) {
      if(adj[v][i] == 1 && d[i] == -1) {
        que.push(i);
        d[i] = d[v] + 1;
      }
    }

  }

  for (int i = 0; i < n; i++) {
    cout << i+1 << ' ' << d[i] << endl;
  }

}