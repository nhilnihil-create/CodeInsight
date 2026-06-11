#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int a[1005][1005];
int in[1000005];
vector<int> g[1000005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - 1; j++) {
      cin >> a[i][j];
    }
    for (int j = 1; j <= n - 2; j++) {
      g[min(i, a[i][j]) * 1000 + max(i, a[i][j])].pb(
          min(i, a[i][j + 1]) * 1000 + max(i, a[i][j + 1]));
      in[min(i, a[i][j + 1]) * 1000 + max(i, a[i][j + 1])]++;
    }
  }
  queue<int> q[2];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!in[i * 1000 + j])
        q[0].push(i * 1000 + j);
    }
  }
  int cnt = 0;
  for (int i = 0;; i ^= 1) {
    while (!q[i].empty()) {
      int u = q[i].front();
      q[i].pop();
      for (int v : g[u]) {
        in[v]--;
        if (!in[v])
          q[i ^ 1].push(v);
      }
    }
    cnt++;
    if (q[i ^ 1].empty())
      break;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (in[i * 1000 + j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << cnt << endl;
}