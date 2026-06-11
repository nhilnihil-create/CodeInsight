#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  int x[n];
  rep(i, n) cin >> x[i];
  int ans = 1001001001;
  f1(p, 1, 100) {
    int now = 0;
    rep(i, n) now += (x[i] - p) * (x[i] - p);
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}