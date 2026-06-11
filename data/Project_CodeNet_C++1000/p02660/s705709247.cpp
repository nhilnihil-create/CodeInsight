#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

using ll = long long;
using P = pair<ll, int>;
using Vi = vector<int>;
using VP = vector<P>;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
// https://github.com/atcoder/live_library/blob/master/prime.cpp

struct Sieve {
  int n;
  Vi f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  Vi factorList(int x) {
    Vi res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  VP factor(int x) {
    Vi fl = factorList(x);
    if (fl.size() == 0) return {};
    VP res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  VP factor(ll x) {
    VP res;
    for (int p : primes) {
      int y = 0;
      while (x % p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p, y);
    }
    if (x != 1) res.emplace_back(x, 1);
    return res;
  }
};

void solve() {
  ll n, ans = 0;
  cin >> n;
  Sieve s(sqrt(n));
  for (const auto &p : s.factor(n)) {
    ll x = p.second;
    ll i = 1;
    while (x >= i) {
      ans++;
      x -= i++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}