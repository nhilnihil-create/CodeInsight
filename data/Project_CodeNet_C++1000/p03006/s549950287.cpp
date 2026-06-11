#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  int ans = 1e9;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  rep(i, n){
    rep(j, n){
      if(i == j) continue;
      ll dx = x[i] - x[j], dy = y[i] - y[j];
      int cost = 0;
      rep(k, n){
        ll tx = x[k] + dx, ty = y[k] + dy;
        cost++;
        rep(l, n){
          if(x[l] == tx && y[l] == ty) cost--;
        }
      }
      ans = min(ans, cost);
      //cout << cost << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
