#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  ll total = 0;
  if (a >= k) {
    total = k;
  } else {
    total = a;
    if (k - a - b > 0) {
      total -= (k - a - b);
    }
  }
  cout << total << endl;
  return 0;
}