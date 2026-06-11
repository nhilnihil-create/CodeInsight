#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<ll> factorList(ll x) {
    vector<ll> res;
    for (int p : primes) {
      while (x%p == 0) {
        res.push_back(p);
        x /= p;
      }
    }
    if (x != 1) res.push_back(x);
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<ll> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<pair<ll,int>> res(1, P(fl[0], 0));
    for (ll p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
  ll n;
  cin >> n;

  vector<pair<ll,int>> fs;
  for (ll i = 2; i*i <= n; ++i) {
    int x = 0;
    while (n%i == 0) {
      n /= i;
      ++x;
    }
    fs.emplace_back(i,x);
  }
  if (n != 1) fs.emplace_back(n,1);

  int ans = 0;
  for (auto p : fs) {
    int x = p.second;
    int b = 1;
    while (b <= x) {
      x -= b;
      b++;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
