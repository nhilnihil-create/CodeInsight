#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

ll div_ceil(ll a, ll b) {
  if (a % b == 0) return a/b;
  return a/b + 1;
}

int main() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll k = lcm(c,d);
  ll n = 0;
  n += b/c - div_ceil(a,c);
  n += b/d - div_ceil(a,d);
  n -= b/k - div_ceil(a,k);
  ll ans = b - a - n;
  cout << ans << endl;
  return 0;
}
