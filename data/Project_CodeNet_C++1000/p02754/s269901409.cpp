#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll initial = n / (a + b);

  ll ans = initial * a;
  n -= initial * (a + b);
  ll diff = 0;

  while (n > 0) {
    diff = min(n, a);
    n -= diff;
    ans += diff;

    diff = min(n, b);
    n -= diff;
  }

  cout << ans << endl;

  return 0;
}
