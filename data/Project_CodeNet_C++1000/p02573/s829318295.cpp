#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 200000;
int n, m;
vector<vector<int>> G(MAX_N); //隣接リスト
bool used[MAX_N]; // 訪問済みかどうか

int dfs(int v) {
  used[v] = true;
  
  int d = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int next = G[v][i];
    if (!used[next]) {
      d += dfs(next);
    }
  }
  return d;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    // 辺を張る
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int d = dfs(i);
    ans = max(ans, d);
  }
  
  cout << ans;
}