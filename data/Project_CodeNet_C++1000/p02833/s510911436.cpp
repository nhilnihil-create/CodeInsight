#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  if (n % 2) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 0;
  for (long long add = n / 10; add > 0; add /= 5) {
    ans += add;
  }
  cout << ans << '\n';
  return 0;
}