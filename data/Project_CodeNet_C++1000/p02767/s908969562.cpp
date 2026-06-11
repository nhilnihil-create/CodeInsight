#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define init() \
  ios::sync_with_stdio(false); \
  cin.tie(0)

#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL

template<typename T>
void show(vector<T>& v) {
    cout << '[';
    for (const T& e : v) {
        cout << e << ',';
    }
    cout << ']' << endl;
}

#endif

template<typename M, typename N>
constexpr common_type_t<M, N> gcd(M a, N b) {
  return a == 0 ? b
    : b == 0 ? a
    : gcd(b, a % b);
}

template <typename M, typename N>
constexpr common_type_t<M, N> lcm(M a, N b) {
  return a * b / gcd(a, b);
}

template <long long MAX>
class CombinationCalculator {
  long long mod_;
  long long fac[MAX];
  long long finv[MAX];
  long long inv[MAX];

public:
  CombinationCalculator(long long mi = MOD): fac(), finv(), inv() {
    mod_ = mi;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % mod_;
      inv[i] = mod_ - inv[mod_ % i] * (mod_ / i) % mod_;
      finv[i] = finv[i - 1] * inv[i] % mod_;
    }
  }

  long long c(long long n, long long k) const {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod_) % mod_;
  }
};

template <long long MAX = 210000>
using CC = CombinationCalculator<MAX>;

template<typename T>
T modpow(T a, T n, T mod = MOD) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template<typename T>
T modinv(T a, T m = MOD) {
    T b = m, u = 1, v = 0;
    while (b) {
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

template<typename T>
vector<T> read_n(const size_t n) {
    T dummy;
    vector<T> v(n);
    for (size_t i = 0; i < n; i++) {
        cin >> dummy;
        v[i] = dummy;
    }
    return v;
}

template<typename T>
vector<T> read_n() {
    size_t n;
    cin >> n;
    return read_n<T>(n);
}

int main() {
  init();

  size_t n;
  cin >> n;
  vector<int> v = read_n<int>(n);

  ull ave = (ull)round(accumulate(all(v), 0.0) / (double)n);
  ull res1 = 0;
  for (const auto& e: v) {
      res1 += (e - ave) * (e - ave);
  }
  cout << res1 << endl;

  return 0;
}
