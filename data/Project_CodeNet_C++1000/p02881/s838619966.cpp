#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;

int main (int argc, char **argv) {
  ll n;
  std::cin >> n;
  ll m = sqrt(n);
  ll ans = n - 1;
  for (int i=2; i <= m; i++) {
    if (n%i==0) {
      ans = std::min(ans, (i-1) + (n/i-1));
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
