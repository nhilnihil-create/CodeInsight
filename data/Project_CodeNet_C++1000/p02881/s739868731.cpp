#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const ll INF = 1e13;

int main() {
  ll n;
  cin >> n;
  ll m = INF;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll j = n / i;
      m = min(m, i - 1 + j - 1);
    }
  }
  cout << m << endl;
  return 0;
}
