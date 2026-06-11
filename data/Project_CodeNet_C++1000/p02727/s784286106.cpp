#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  vi kouho;
  rep(i,x) kouho.push_back(p[i]);
  rep(i,y) kouho.push_back(q[i]);
  rep(i,c) kouho.push_back(r[i]);
  sort(kouho.rbegin(),kouho.rend());
  ll ans=0;
  rep(i,x+y) ans += kouho[i];
  cout << ans << endl;
}
