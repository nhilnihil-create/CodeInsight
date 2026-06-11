#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

template<typename T>
constexpr T inf = static_cast<T>(pow(10, static_cast<int>(log10(numeric_limits<T>::max())))) + 7;
constexpr llong mod = 1e9+7;

int main() {
  llong M, D;
  cin >> M >> D;

  llong ans = 0;
  for (int m = 1; m <= M; ++m) {
    for (int d = 1; d <= D; ++d) {
      if (d/10 == 1 || d%10 == 1) continue;

      ans += (d/10) * (d%10) == m;
    }
  }

  cout << ans << endl;

  return 0;
}