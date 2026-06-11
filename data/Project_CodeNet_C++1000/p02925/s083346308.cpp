#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 500000;
vector<int> g[MAX];
int m[MAX]; bool used[MAX];

int dfs(int u){
  if(used[u]) return -1;
  if(m[u]!=0) return m[u];

  int res = 0;
  used[u] = true;
  m[u] = 1;
  for(int v:g[u]) {
    int res = dfs(v);
    if(res<0) return m[u] = -1;
    m[u] = max(m[u],res+1);
  }
  used[u] = false;
  return m[u];
}
int main() {
  int n;
  cin >> n;

  vector<vector<int>> a(n,vector<int>(n-1));
  rep(i,n)rep(j,n-1){
    cin >> a[i][j];
    --a[i][j];
  }
  vector<vector<int>> id(n,vector<int>(n));
  int v = 0;
  rep(i,n)rep(j,n) if(i<j) id[i][j] = id[j][i] = v++;

  rep(i,n){
    int p = id[i][a[i][0]];
    rep(j,n-2){
      int np = id[i][a[i][j+1]];
      g[p].emplace_back(np);
      p = np;
    }
  }

  int ans = 0;
  rep(i,n){
    int temp = dfs(id[i][a[i][0]]);
    if(temp<0){
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans,temp);
  }
  cout << ans << endl;
}
