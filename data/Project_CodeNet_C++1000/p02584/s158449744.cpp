#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <math.h>

#define rep(i, n) for (auto i = 0; i < (n); i++)
#define MOD 1e9 + 7
typedef long long ll;

using namespace std;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  ll t = (ll)round((long double)abs(x)/d);
  if (x > 0) {
    if (k <= t) {
      cout << abs(x - k * d) << endl;
    } else {
      if ((k - t) % 2 == 0) {
        cout << abs(x - t * d) << endl;
      } else {
        ll c1 = abs(x - t * d + d);
        ll c2 = abs(x - t * d - d);
        cout << min(c1, c2) << endl;
      }
    }
  } else {
    if (k <= t) {
      cout << abs(x + k * d) << endl;
    } else {
      if ((k - t) % 2 == 0) {
        cout << abs(x + t * d) << endl;
      } else {
        ll c1 = abs(x + t * d + d);
        ll c2 = abs(x + t * d - d);
        cout << min(c1, c2) << endl;
      }
    }
  }

  return 0;
}

