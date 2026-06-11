#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a;
  ll b, n;
  cin >> a >> b >> n;

  if (n < b) {
    // x should be n
  }

  ll x = min(n, b - 1);
  ll ans = floor((a * x) / b) - (a * floor(x / b));
  cout << ans << endl;

  return 0;
}
