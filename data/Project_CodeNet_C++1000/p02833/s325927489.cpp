#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

ll f(unsigned long long n) {
  if (n < 2) {
    return 1;
  } else {
    return n * f(n - 2);
  }
}

int main() {
  ll n;
  cin >> n;
  ll res = 0;
  if (n % 2 == 1) {
    res = 0;
  } else {
    n /= 2;
    ll div = 5;
    while (div <= n) {
      res += n / div;
      div *= 5;
    }
  }
  cout << res << endl;
  return 0;
}

