#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll gcd(ll a, ll b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    res[n]++;
  }
  return res;
}

ll N, M;
ll b[101010];

int main() {
  cin >> N >> M;
  ll a;
  cin >> a;
  ll cnt = 0;
  while (a % 2 == 0) {
    ++cnt;
    a /= 2;
  }
  b[0] = a;

  rep(i, 1, N) {
    cin >> a;
    ll cnt2 = 0;
    while (a % 2 == 0) {
      ++cnt2;
      a /= 2;
    }
    if (cnt2 != cnt) {
      cout << 0;
      return 0;
    }
    b[i] = a;
  }

  ll div = 1;
  rep(i, 0, cnt - 1) { div *= 2; }
  M /= div;

  ll l = 1;
  rep(i, 0, N) { l = lcm(l, b[i]); }

  cout << (M / l + 1) / 2 << endl;
}
