#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool is_prime(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

map<ll, int> prime_factor(ll n) {
  map<ll, int> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n]++;
  return res;
}

vector<ll> prime_enum(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<ll> res;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    res.push_back(i);
    for (int j = 2 * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll g = __gcd(a, b);
  auto mp = prime_factor(g);
  cout << 1 + mp.size() << endl;
}
