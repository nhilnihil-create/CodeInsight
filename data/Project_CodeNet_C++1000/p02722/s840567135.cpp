#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans = 1;
  for (ll i = 1; i * i <= n - 1; i++) {
    if ((n - 1) % i == 0) {
      ans += 2;
    }
    if (i == 1 || i * i == n - 1) {
      ans--;
    }
  }
  for (ll k = 2; k * k <= n; k++) {
    if (n % k) {
      continue;
    }
    ll tmp = n;
    while (tmp % k == 0) {
      tmp /= k;
    }
    if (tmp % k == 1) {
      ans++;
    }
    ll tmpk = n / k;
    tmp = n;
    while (tmp % tmpk == 0) {
      tmp /= tmpk;
    }
    if (k * k != n && tmp % tmpk == 1) {
      ans++;
    }
  }
  cout << (n == 2 ? 1 : ans) << endl;
  return 0;
}
