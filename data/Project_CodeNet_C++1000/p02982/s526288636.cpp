#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n){
    rep(j,d){
      cin >> x[i][j];
    }
  }
  int ans = 0;
  rep(i1,n){
    rep(i2,n){
      int l = 0;
      if(!(i2 > i1)) continue;
      rep(j,d){
        l += (x[i1][j] - x[i2][j])*(x[i1][j] - x[i2][j]);
      }
      rep(k,180){
        if(l == k*k) ans++;
      }
    }
  }
  cout << ans << endl;
}