#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  ll p = 5;
  n /= 2;
  while (p <= n) {
    ans += n/p;
    p *= 5;
  }
  printf("%lld\n", ans);
  return 0;
}
