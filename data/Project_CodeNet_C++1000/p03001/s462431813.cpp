#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll w, h, x, y; cin >> w >> h >> x >> y;
  double s = w * h / 2.0;
  int cnt, ans=0;
  if (w == x*2) cnt++;
  if (h == y*2) cnt++;
  if (cnt > 1) ans = 1;
  cout << fixed << setprecision(10);
  cout << s << " " << ans << endl;
  return 0;
}