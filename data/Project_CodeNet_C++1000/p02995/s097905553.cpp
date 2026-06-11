#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


ll lcm(ll x, ll y){
  ll ans;
  ans = x /__gcd(x,y) * y;
  return ans;

}

int main(){
  ll a, b;
  ll c, d;
  cin >> a >> b >> c >> d;

  ll x, y, xy;
  x = b/c - (a-1)/c;
  y = b/d - (a-1)/d;
  ll e = lcm(c,d);
  xy = b/e - (a-1)/e;

  //cout << x << " " << y << " " << xy << endl;

  ll ans;
  ans = b - a + 1 - x - y + xy;

  cout << ans << endl;

  return 0;
}
