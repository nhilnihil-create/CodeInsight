#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int cnt = 0;
  vector<int> dist(n, -1);
  rep(sv,n) {
    if(dist[sv] != -1) continue;
    queue<int> q;
    dist[sv] = 0;
    q.push(sv);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(int nv : G[v]) {
        if(dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        q.push(nv);
      }
    }
    cnt++;
  }
  int ans = cnt-1;
  cout << ans << endl;
  return 0;
}