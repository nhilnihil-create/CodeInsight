#include <iostream>
using namespace std;
using ll = int64_t;
int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = k; i <= n + 1; ++i) { ans = (ans + i * (n + 1 - i) + 1) % 1000000007; }
  cout << ans << endl;
  return 0;
}