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

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << adj[i][j] << (j == n-1 ? '\n' : ' ');
    }
  }
}