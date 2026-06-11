#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct mint {
  ll x;
  mint() : x(0) {
  }
  mint(ll x) : x((x % MOD + MOD) % MOD) {
  }
  mint& operator+=(const mint& r) {
    if ((x += r.x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  mint& operator-=(const mint& r) {
    if ((x -= r.x) < 0) {
      x += MOD;
    }
    return *this;
  }
  mint& operator*=(const mint& r) {
    if ((x *= r.x) > MOD) {
      x %= MOD;
    }
    return *this;
  }
  mint& operator++() {
    if ((++x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  mint operator++(int) {
    mint ret = x;
    if ((++x) >= MOD) {
      x -= MOD;
    }
    return ret;
  }
  mint& operator--() {
    if ((--x) < 0) {
      x += MOD;
    }
    return *this;
  }
  mint operator--(int) {
    mint ret = x;
    if ((--x) < 0) {
      x += MOD;
    }
    return ret;
  }
  mint operator+(const mint& r) {
    mint ret;
    return ret = x + r.x;
  }
  mint operator-(const mint& r) {
    mint ret;
    return ret = x - r.x;
  }
  mint operator*(const mint& r) {
    mint ret;
    return ret = x * r.x;
  }
  mint operator-() {
    return mint() - *this;
  }
  bool operator<(const mint& a) {
    return x < a.x;
  }
  bool operator>(const mint& a) {
    return x > a.x;
  }
  bool operator<=(const mint& a) {
    return x <= a.x;
  }
  bool operator>=(const mint& a) {
    return x >= a.x;
  }
  bool operator==(const mint& a) {
    return x == a.x;
  }
  bool operator!=(const mint& a) {
    return x != a.x;
  }
};
ostream& operator<<(ostream& os, const mint& r) {
  os << r.x;
  return os;
}
ostream& operator>>(ostream& os, const mint& r) {
  os >> r.x;
  return os;
}


ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

ll combination(ll n, ll r){
  ll num = 1;
  for(int i = 1; i <= r; i++){
      num = num * (n - i + 1) % MOD;
      num = num * modinv(r - i + 1, MOD) % MOD;
  }
  return num;
}

void solve(istream& cin, ostream& cout) {
  int x, y;
  cin >> x >> y;
  if ((x + y) % 3 != 0) {
    cout << 0 << endl;
    return;
  }
  int n = (x + y) / 3;
  x -= n;
  y -= n;
  if (x < 0 || y < 0) {
    cout << 0 << endl;
    return;
  }
  mint ans = combination((x + y), x);
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
