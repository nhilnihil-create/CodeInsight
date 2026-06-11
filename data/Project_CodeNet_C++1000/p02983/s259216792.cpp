#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

int main() {
  ll l, r;
  cin >> l >> r;

  if (2000 < r - l)
    cout << 0 << endl;
  else {
    ll vmin = INT_MAX;
    for (ll i = l; i < r; ++i)
      for (ll j = i + 1; j <= r; ++j)
        if ((i * j) % 2019 < vmin)
          vmin = (i * j) % 2019;
    cout << vmin << endl;
  }
}