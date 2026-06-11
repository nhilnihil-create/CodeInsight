#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> a(n,vector<int>(m)); 
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
    rep(j,m){
      cin >> a[i][j];
    }
  }
  int ans = 100000000;
  rep(i,(1<<n)){
    vector<int> skill(m,0);
    int cost = 0;
    rep(j,n){
      if(!(i & (1<<j))) continue;
      cost += c[j];
      rep(k,m) skill[k] += a[j][k];
    }
    if(ans < cost) continue;
    int ok = 1;
    rep(k,m){
      if(skill[k] < x){
        ok = -1;
        break;
      }
    }
    if(ok == 1) ans = cost;
  }
  if(ans == 100000000) ans = -1;
  cout << ans << endl;
  return 0;
}
