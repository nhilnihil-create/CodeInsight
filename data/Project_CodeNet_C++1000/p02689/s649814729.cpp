#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)n;(i)++)
int main(){
  int n,m; cin >> n >> m;
  vector<int> h(n);
  rep(i,n){
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  rep(i,n){
    bool f = true;
    rep(j,g[i].size()){
      if(h[g[i][j]] >= h[i]){
        f = false;
        break;
      }
    }
    if(f) {
      ans++;
    }
  }
  cout << ans << endl;
    
}