#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> adj[N];
int val[N];
void dfs(int s, int p) {
  for (int nbr : adj[s]) {
    if (nbr != p) {
      val[nbr] += val[s];
      dfs(nbr, s);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while (q--) {
    int p, x;
    cin >> p >> x;
    p--;
    val[p] += x;
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++)
    cout << val[i] << ' ';
  return 0;
}