#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll x = n / (a + b);
  ll ans = x * a + min(a, n % (a + b));
  cout << ans << endl;
  return 0;
}