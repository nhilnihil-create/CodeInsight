#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 998244353;

int main(){
  int x, y, a, b, c; cin>> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];
  
  sort(p.begin(), p.end(), greater<int>());
  sort(q.begin(), q.end(), greater<int>());
  sort(r.begin(), r.end(), greater<int>());

  int u, v;
  u = x-1, v= y-1;
  int i = 0;
  while(r[i] > p[u] || r[i] > q[v] || i < c ){
    if(p[u] > q[v]){q[v]  = max(q[v], r[i]); v--;}
    else{p[u] = max(p[u], r[i]); u--;}
    if(u < 0) u = 0; if(v < 0) v = 0;
    i++;
  }
  
  ll ans = 0;
  rep(i, x) ans += p[i];
  rep(i, y) ans += q[i];
    
  cout << ans << endl;
  
   
  return 0;
}
