// #include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

// using namespace std;
// using ll = long long;

// const int mod = 1000000007;
// struct mint {
//   ll x;
//   mint(ll x = 0) : x(x % mod) {}
//   mint operator-() const { return mint(-x); }
//   mint& operator+=(const mint a) {
//     if ((x += a.x) >= mod) {
//       x -= mod;
//     }
//     return *this;
//   }
//   mint& operator-=(const mint a) {
//     if ((x += mod - a.x) >= mod) {
//       x -= mod;
//     }
//     return *this;
//   }
//   mint& operator*=(const mint a) {
//     (x *= a.x) %= mod;
//     return *this;
//   }
//   mint operator+(const mint a) const {
//     mint res(*this);
//     return res += a;
//   }
//   mint operator-(const mint a) const {
//     mint res(*this);
//     return res -= a;
//   }
//   mint operator*(const mint a) const {
//     mint res(*this);
//     return res *= a;
//   }
//   mint pow(ll t) const {
//     if (!t) {
//       return 1;
//     }
//     mint a = pow(t >> 1);
//     a *= a;
//     if (t & 1) {
//       a *= *this;
//     }
//     return a;
//   }

//   mint inv() const { return pow(mod - 2); }
//   mint& operator/=(const mint a) { return (*this) *= a.inv(); }
//   mint operator/(const mint a) const {
//     mint res(*this);
//     return res /= a;
//   }
// };

// mint f(int n) {
//   if (n == 0) {
//     return 1;
//   }
//   mint x = f(n / 2);
//   x *= x;
//   if (n % 2 == 1) {
//     x *= 2;
//   }
//   return x;
// }
// mint choose(int n, int a) {
//   mint x = 1, y = 1;
//   rep(i, a) {
//     x *= n - i;
//     y *= i + 1;
//   }
//   return x / y;
// }
// int main() {
//   int n, a, b;
//   cin >> n >> a >> b;
//   mint ans = f(n);
//   ans -= 1;
//   ans -= choose(n, a);
//   ans -= choose(n, b);
//   cout << ans.x << endl;
//   return 0;
// }

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

ll mod_pow(ll n, ll x) {
  if (x == 0) return 1;
  if (x == 1) return n;
  ll v = mod_pow(n, x/2);
  v *= v;
  v %= MOD;
  if (x%2 == 1) v *= n;
  return v % MOD;
}

ll mod_inv(ll a) {
  return mod_pow(a, MOD - 2) % MOD;
}

ll nck(ll n, ll k) { 
  ll x = 1, y = 1;
  for (ll i = 0; i < k; i++) {
    x *= n-i;
    x %= MOD;
    y *= mod_inv(i+1);
    y %= MOD;
  }
  return (x * y) % MOD;
}

int mod(ll n) {
  n %= MOD;
  if (n < 0) n += MOD;

  return n;
}

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;
  ll v = mod_pow(2, n) - nck(n, a) - nck(n, b) - (ll)1;
  cout << mod(v) << endl;
  
  return 0;
}
