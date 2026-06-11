#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; i++) {
      if (f[i]) {
        continue;
      }
      f[i] = i;
      primes.emplace_back(i);
      for (ll j = i * i; j <= n; j += i) {
        if (!f[j]) {
          f[j] = i;
        }
      }
    }
  }
  bool isPrime(int x) { return x == f[x]; }
};

int main() {
  Sieve sieve(1e6);
  int x;
  cin >> x;
  for (int i = x; x < 1e6; x++) {
    if (sieve.isPrime(x)) {
      cout << x << endl;
      return 0;
    }
  }
  return 0;
}
