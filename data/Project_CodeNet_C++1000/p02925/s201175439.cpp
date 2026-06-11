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

map<P,vector<P>> g;
map<P,int> m; set<P> used;
int dfs(P u){
  if(used.count(u)>0) return -1;
  if(m[u]!=0) return m[u];

  int res = 0;
  used.insert(u);
  for(P v:g[u]) {
    int temp = dfs(v);
    if(temp<0) return m[u] = -1;
    res = max(res,temp);
  }
  used.erase(u);
  return m[u] = res + 1;
}

int main() {
  int n;
  cin >> n;
  vector<P> v;
  rep(a,n){
    P p;
    rep(i,n-1){
      int b;
      cin >> b;
      --b;
      P np = a<b ? P(a,b) : P(b,a);
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
