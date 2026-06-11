// 改善版
#include <bits/stdc++.h>
using namespace std;

static const int MAX = 1001001;

// 閉路検出
vector<int> G[MAX], color(MAX, 0);
// main関数からこれらを削除すること

bool cycle(int u) {
  color[u] = 1; // GRAY
  bool ret;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if(color[v] == 1) return true;
    if(color[v] == 0) ret = cycle(v);
  }
  color[u] = 2; // BLACK
  return ret;
}

// 隣接リストを用いた深さ優先探索（再帰ver.） O(|V|+|E|)
vector<int> dist(MAX, 1e9);
// main関数からこれらを削除すること

int dfs(int u) {
  int keep = -1;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if(dist[v] != 1e9) keep = max(keep, dist[v]);
    else keep = max(keep, dfs(v));
  }
  if(keep == -1){
    dist[u] = 1;
    return 1;
  }
  else{
    dist[u] = keep + 1;
    return keep + 1;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<int>> a(n, vector<int>(n - 1));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 1; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  // vector<int> G[1001001]; // G:頂点数がnのグラフを表す隣接リスト
  
  for(int i = 0; i < n; i++){
    for(int j = 1; j < n - 1; j++){
      int w = i + 1, x = i + 1, y = a.at(i).at(j - 1), z = a.at(i).at(j);
      if(w > y) swap(w, y);
      if(x > z) swap(x, z);
      G[w * 1000 + y].emplace_back(x * 1000 + z);
    }
  }
  
  bool check;
  for(int i = 0; i < MAX; i++){
    if(color.at(i) == 0) check = cycle(i);
    if(check){
      cout << "-1\n";
      return 0;
    }
  }
  
  int ans = 0;
  for(int i = 0; i < MAX; i++){
    if(dist.at(i) == 1e9) ans = max(ans, dfs(i));
  }
  
  cout << ans << '\n';
}