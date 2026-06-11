#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  vector<ll> d;
  rep(i,x) d.push_back(p[i]);
  rep(i,y) d.push_back(q[i]);
  rep(i,c) d.push_back(r[i]);
  ll ans = 0;
  sort(d.rbegin(), d.rend());
  rep(i,x+y) ans += d[i];
  cout << ans << endl;
  return 0;
}