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

map<int,vector<int>> g;
map<int,int> m; map<int,bool> used;
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
  auto id = [n](int i, int j){
    if(i>j) swap(i,j);
    return i*n+j;
  };
  vector<int> v;
  rep(a,n){
    int p;
    rep(i,n-1){
      int b;
      cin >> b;
      --b;
      int np = id(a,b);
      if(i>0) g[p].emplace_back(np);
      else v.emplace_back(np);
      p = np;
    }
  }
  int ans = 0;
  rep(i,v.size()){
    int temp = dfs(v[i]);
    if(temp<0){
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans,temp);
  }
  cout << ans << endl;
}
