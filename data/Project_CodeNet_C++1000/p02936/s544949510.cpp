#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[200005];
vector<int> ans;
vector<bool> visited;

void dfs(int v, int p=-1) {
  for (int u : adj[v]) {
    if (u == p) continue;
    ans[u] += ans[v];
    dfs(u,v);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ans.resize(n);
  for(int i=0;i<q;i++) {
    int p, x;
    cin >> p >> x;
    --p;
    ans[p] += x;
  }
  dfs(0);
  for(int i=0;i<n;i++) {
    cout << ans[i] << endl;
  }
  return 0;
}