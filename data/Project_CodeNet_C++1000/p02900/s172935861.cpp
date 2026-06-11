#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

vector<pair<ll, ll>> primeFactorize(ll n) {
  vector<pair<ll, ll>> r;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    ll ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    r.push_back({i, ex});
  }
  if (n > 1) {
    r.push_back({n, 1});
  }
  return r;
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll g = gcd(A, B);
  auto res = primeFactorize(g);
  ll v = 1;
  for (auto r: res) {
		v++;
  }
	cout << v <<endl;
}
