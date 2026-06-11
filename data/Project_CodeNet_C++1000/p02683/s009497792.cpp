#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  ll n,m,x,ans=2000000;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vector<vector<ll>> a(n, vector<ll>(m));
  rep(i,n){
    cin >> c.at(i);
    rep(j,m){
      cin >> a.at(i).at(j);
    }
  }
  
  rep(s,1<<n){
    ll money = 0;
    vector<ll> check(m,0);
    rep(i,n){
      if(((s>>i)&1) == 1){
        rep(j,m){
          check.at(j) += a.at(i).at(j);
        }
        money += c.at(i);
      }
    }
    ll count = 0;
    rep(j,m){
      if(check.at(j) < x){count++;}
    }
    if(count == 0){
      ans = min(ans,money);
    }
  }
  
  if(ans == 2000000){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
  
  return 0;
}
