#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  ll n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
 
  ll ans = 0, d = 10;
  while (d <= n) {
    ans += n / d;
    d *= 5;
  }
 
  cout << ans << endl;
  return 0;
}