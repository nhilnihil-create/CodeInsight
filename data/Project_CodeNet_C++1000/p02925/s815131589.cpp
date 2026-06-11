#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 1e9+1;

auto ToplogicalSort (vector<vector<int>>& g, int n, int v_size){

  int res = 0;    

  vector<int> dp(n,0);
  vector<int> check(n,0);

  auto dfs = [&](auto& f, int u) -> int {

    if (dp[u] != 0) {
      if (!check[u]) return -1;
      return dp[u];
    }

    dp[u] = 1;

    for (auto v : g[u]) {
      int res = f(f, v);
      if (res == -1) return -1;
      dp[u] = max(dp[u], res + 1);
    }

    check[u] = 1;
    return dp[u];
  };
  
  for (int i = 0; i < v_size; i++) {
    int d = dfs(dfs, i);
    if (d == -1) {
      return -1;
    }
    res = max(res, d);
  }
  return res;
}

int main(){
  int n, m;
  cin >> n;
  m = n-1;
  
  vector<vector<int>> aa(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> aa[i][j];
      aa[i][j]--;
    }
  }

  vector<vector<int>> id(n, vector<int>(n));
  int v = 0;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) if (i < j) id[i][j] = v++; 

  vector<vector<int>> g(v);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m -1 ; j++) {
      int a = i, b = aa[i][j], c = i, d = aa[i][j + 1];
      if (a > b) swap(a, b);
      if (c > d) swap(c, d);
      g[id[a][b]].emplace_back(id[c][d]);
    }
  }
  int k = n * (n - 1) / 2;

  cout << ToplogicalSort(g, k, v) << endl;

  return 0;
} 