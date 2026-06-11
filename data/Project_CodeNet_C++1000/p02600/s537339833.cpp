#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main(void) {
  ll x, ans;
  cin >> x;
  if (x <= 599) ans = 8;
  else if (x <= 799) ans = 7;
  else if (x <= 999) ans = 6;
  else if (x <= 1199) ans = 5;
  else if (x <= 1399) ans = 4;
  else if (x <= 1599) ans = 3;
  else if (x <= 1799) ans = 2;
  else if (x <= 1999) ans = 1;
  cout << ans << endl;
  return 0;
}
