#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int primeFactorize(ll n) {
  int count = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    int ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    count *= (ex + 1);
  }
  if (n > 1) {
    count *= 2;
  }
  return count;
}

int main() {
  ll n;
  cin >> n;
  ll r = 0;

  for (int c = 1; c < n; c++) {
    ll v = n - c;
    r += primeFactorize(v);
  }
	cout << r << endl;
}
