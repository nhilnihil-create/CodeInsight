#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  int ans = 1;
  for (ll k = 2; k * k <= n; k++) {
    ll n_ = n;
    if (n_ % k) continue; 
    while (n_ % k == 0) n_ /= k;
    if (n_ % k == 1) ans++;
  }
  n--;
  if (n > 1) ans++;
  for (ll k = 2; k * k <= n; k++) {
    if (n % k == 0) ans += 2;
    if (k * k == n) ans--;
  }

  cout << ans << endl;
  return 0;
}