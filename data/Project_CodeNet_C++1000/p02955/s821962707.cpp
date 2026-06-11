#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
const long long INF = 1LL << 60;

bool is_prime(const unsigned n) {
  if (n % 2 == 0 || n % 3 == 0) {
    if (n == 2 || n == 3) {
      return true;
    }
    return false;
  }
  if (n == 1) {
    return false;
  }

  for (unsigned i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

// prime factorization (素因数分解)
// key: value of prime factor
// value: number of prime factor
std::map<ll, ll> prime_factorization(ll n) {
  std::map<ll, ll> prime_factors;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      prime_factors[i]++;
      n /= i;
    }
  }
  if (n != 1)
    prime_factors[n] = 1;
  return prime_factors;
}

using ll = long long;
using ld = long double;

// 約数リスト
vector<ll> get_divisors(const ll n) {
  vector<ll> divs;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) {
        divs.push_back(n / i);
      }
    }
  }

  // 必要に応じてソート
  sort(divs.begin(), divs.end());

  return divs;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, k;
  cin >> n >> k;

  ll sum = 0;
  vll a(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  auto divisors = get_divisors(sum);
  reverse(all(divisors));

  ll ans = -1;
  for (ll v : divisors) {
    vll d(n);
    rep(i, n) {
      d[i] = a[i] % v;
    }
    sort(all(d));
    ll l = 0;
    ll r = 0;
    rep(i, n) {
      if (d[i] != 0) {
        r += v - d[i];
      }
    }
    int tmp;
    rep(i, n) {
      if (l == r) {
        break;
      }
      if (d[i] == 0) {
        continue;
      }
      l += d[i];
      r -= v - d[i];
    }
    if (l <= k) {
      ans = v;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
