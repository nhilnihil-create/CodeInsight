#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  vi c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i,n){
    cin >> c[i];
    rep(j,m) cin >> a[i][j];
  }
  ll ans = 1000000000000000000;
  rep(is,1<<n){
    ll money=0;
    vi total(m,0);
    rep(i,n){
      if(is>>i&1){
        rep(j,m) total[j] += a[i][j];
        money += c[i];
      }
    }
    sort(total.begin(),total.end());
    //cout << total[0] << endl;
    if(total[0] >= x) ans = min(ans, money);
  }
  if(ans == 1000000000000000000) cout << -1 << endl;
  else cout << ans << endl;
}
