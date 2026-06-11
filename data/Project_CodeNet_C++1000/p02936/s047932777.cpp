#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,q;
int counter[200000];
vector<int> children[200000];
bool visited[200000];

void dfs(int v) {
  visited[v] = true;
  for(auto u : children[v]) {
    if(visited[u]) continue;
    counter[u] += counter[v];
    dfs(u);
  }
}

signed main() {
  cin >> n >> q;
  rep(i, n-1) {
    int a,b; cin >> a >> b; --a, --b;
    children[a].push_back(b);
    children[b].push_back(a);
  }
  rep(i,q) {
    int p,x; cin >> p >> x; --p;
    counter[p] += x;
  }
  dfs(0);
  rep(i,n) cout << counter[i] << (i==n-1 ? "\n" : " ");
}
