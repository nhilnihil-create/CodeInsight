#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a), q(b), r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(rng(p)); reverse(rng(p));
  sort(rng(q)); reverse(rng(q));
  rep(i,x) r.push_back(p[i]);
  rep(i,y) r.push_back(q[i]);
  sort(rng(r)); reverse(rng(r));
  ll ans = 0;
  rep(i,x+y) ans += r[i];
  cout << ans << endl;
  return 0;
}