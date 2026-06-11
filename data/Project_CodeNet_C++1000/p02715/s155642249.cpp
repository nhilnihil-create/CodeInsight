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

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX];
long long finv[MAX];
long long inv[MAX]; // mod MOD k の逆元 inv[k]

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if(n < k)
    return 0;
  if(n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 順列計算
long long perm(long long a, long long b) {
  if(a < b)
    return 0;
  long long tmp = finv[a - b] % MOD;
  return tmp * fac[a] % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;

  VLL sum(k + 1, 0);
  vm gcdCnt(k + 1, 0);

  mint ans = 0;

  FOR(i, 1, k + 1) { sum[i] = k / i; }
  for(int i = k; i >= 1; i--) {
    gcdCnt[i] = modPow(sum[i], n);

    ll x = 2;
    while(i * x <= k) {
      gcdCnt[i] -= gcdCnt[i * x];
      x++;
    }

    ans += (mint)i * gcdCnt[i];
  }

  cout << ans << endl;
  return 0;
}
