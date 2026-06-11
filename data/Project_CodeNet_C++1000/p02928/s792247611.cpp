#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// const value
// const ll MOD = 1e9 + 7;
// const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
// const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline ll toLL(string s) {
  ll v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

//* Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint() : x(0) {}
  mint(ll x) : x((x % mod + mod) % mod) {}
  // mint(ll x):x(x){}
  mint &fix() {
    x = (x % mod + mod) % mod;
    return *this;
  }
  mint operator-() const { return mint(0) - *this; }
  mint &operator+=(const mint &a) {
    if((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint &a) {
    if((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint &a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
};
istream &operator>>(istream &i, mint &a) {
  i >> a.x;
  return i;
}
ostream &operator<<(ostream &o, const mint &a) {
  o << a.x;
  return o;
}
typedef vector<mint> vm;
typedef vector<vm> vvm;
//*/
long long modPow(long long x, long long n) {
  if(n == 0)
    return 1;
  if(n % 2 == 0) {
    long long sqrtX = modPow(x, n / 2);
    return sqrtX * sqrtX % mod;
  } else {
    return x * modPow(x, n - 1) % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  VLL a(n);
  rep(i, n) cin >> a[i];
  vector<mint> right(n, 0);
  vector<mint> sum(n, 0);
  rep(i, n) {
    FOR(j, i + 1, n) {
      if(a[i] > a[j]) {
        right[i] += 1;
      }
    }
  }

  rep(i, n) {
    rep(j, n) {
      if(a[i] > a[j]) {
        sum[i] += 1;
      }
    }
  }
  mint ans = 0;
  mint kk = k;
  rep(i, n) {
    ans += right[i] * k;
    ans += (kk - 1) * ((mint)(2) * sum[i] + mint(kk - 2ll) * sum[i]) *
           modPow(2ll, mod - 2);
  }
  cout << ans << endl;

  return 0;
}
