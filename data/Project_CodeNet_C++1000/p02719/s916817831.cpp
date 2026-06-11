#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  ll n, k;
  cin >> n >> k;
  n %= k;
  ll ans = min(n, k - n);
  cout << ans << endl;
  return 0;
}