#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i,0,n)
#define BFOR(bit,a,b) for(int bit = (a); bit < (1<<(b)); ++bit)
#define BREP(bit,n) BFOR(bit,0,n)
using namespace std;
using ll = long long;

int main() {
  ll n,m,x;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vector<vector<ll>> a(n,vector<ll> (m));
  
  REP(i,n){
    cin >> c[i];
    REP(j,m){
      cin >> a[i][j];
    }
  }
  
  ll ans = 100000000000;
  BREP(bit,n){
    ll sum = 0;
    vector<ll> ex(m);
    REP(i,n){
      if((bit>>i) & 1) continue;
      sum += c[i];
      REP(j,m){
        ex[j] += a[i][j];
      }
    }
    
    bool can = true;
    REP(i,m){
      if(ex[i] < x) can = false;
    }
    
    if(can) ans = min(ans,sum);
  }
  
  if(ans == 100000000000) cout << -1 << endl;
  else cout << ans << endl;
      
      
    
}