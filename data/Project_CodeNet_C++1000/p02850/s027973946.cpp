#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

vector<P> G[100000];
int colors[100000];

void dfs(int node, int from, int from_color){
  int color = 1;
  for (auto e : G[node]){
    int to = e.first, cur = e.second;
    if (to == from) continue;
    if (color == from_color) color++;
    colors[cur] = color;
    dfs(to, node, color);
    color++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  int max_edge = 0;
  for(auto g : G)chmax(max_edge, (int)g.size());

  dfs(0,-1,-1);
  cout<<max_edge<<endl;
  rep(i,0,n-1)cout<<colors[i]<<endl;
}
