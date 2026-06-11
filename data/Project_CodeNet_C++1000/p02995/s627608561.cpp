#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll ans = b-a+1;
  ll e = c/gcd(c,d)*d;
  ans -= b/c-(a-1)/c+b/d-(a-1)/d-(b/e-(a-1)/e);
  cout << ans << endl;
  return 0;
}