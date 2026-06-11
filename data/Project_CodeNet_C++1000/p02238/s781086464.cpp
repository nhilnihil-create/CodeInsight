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

  int d[n] = {};
  int f[n] = {};
  int t = 1;

  stack<int> st;
  st.push(0);

  while (!st.empty()) {
    int v = st.top();

    if(d[v] == 0) {
      d[v] = t;
    }

    for (int i = 0; i < n; i++) {
      if(adj[v][i] == 1 && d[i] == 0) {
        st.push(i);
        break;
      }
    }

    if(st.top() == v) {
      f[v] = t+1;
      st.pop();
    }

    if(st.empty()) {
      t++;
      for (int i = 0; i < n; i++) {
        if(d[i] == 0) {
          st.push(i);
          break;
        }
      }
    }

    t++;
  }

  for (int i = 0; i < n; i++) {
    cout << i+1 << ' ' << d[i] << ' ' << f[i] << endl;
  }

}