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

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  int t = 0;ll p = a[0];
  while(p % 2 == 0) { t++; p /= 2; }
  bool flag = false;
  rep(i,1,n) {
    p = a[i];
    int s = 0;
    while(p % 2 == 0) { s++; p /= 2;}
    if (t != s) {
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << 0 << endl;
    return 0;
  }
  int l = 1;
  rep(i,0,n) {
    l = lcm(l,a[i]);
    if (l > 2*m) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = (m + l/2) / l;
  cout << ans << endl;
  return 0;
}
