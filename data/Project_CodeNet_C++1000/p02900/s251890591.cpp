#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll g = __gcd(a, b);
  int res = 0;
  for (ll x = 2; x * x <= g; x++) {
    if (g % x == 0) {
      res++;
      while (g % x == 0) g /= x;
    }
  }
  if (g > 1) res++;
  cout << res + 1 << endl;
  return 0;
}
