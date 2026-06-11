#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

struct mint {
  ll x;
  mint(ll x=0) : x(x%mod) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x -= a.x) < 0) x += mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) {
    mint res(*this);
    return res*=a;
  }
};

const int MAX = 100'000 + 5;
ll fac[MAX], finv[MAX], inv[MAX];

void initComb() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  srep(i, 2, MAX) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}
ll comb(ll n, ll k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int n, k;
vvi to;
mint ans;

void dfs(int v, int p=-1) {
  for (auto &u : to[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  int nk = (p==-1) ? k : k-2;
  int c = (p==-1) ? to[v].size()+1 : to[v].size()-1;
  ans *= comb(nk, c) * fac[c];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  initComb();
  std::cin >> n >> k;
  to.resize(n);
  rep(i, n-1) {
    int a, b; std::cin >> a >> b;
    --a, --b;
    to[a].pb(b), to[b].pb(a);
  }
  ans = 1;
  dfs(0);
  std::cout << ans.x << "\n";
}
