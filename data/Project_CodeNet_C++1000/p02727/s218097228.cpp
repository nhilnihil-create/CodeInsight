#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


// At first, fix the number of red apple
// How to maximize Y selection
// get the best green apple numbers in 10^3
//max is Y.


int main(){
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  
  rep(i,x) r.push_back(p[i]);
  rep(i,y) r.push_back(q[i]);
  sort(r.rbegin(),r.rend());

  ll ans = 0;
  rep(i,x+y) ans += r[i];
  cout << ans << endl;
 }
