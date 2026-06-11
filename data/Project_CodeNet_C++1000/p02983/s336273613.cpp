#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  ll l, r;
  cin >> l >> r;
  int first = l % 2019;
  int last = r % 2019;
  if (r - l + 1 >= 2019 || first > last) {
    cout << 0 << endl;
  } else {
    int ans = 2020;
    for (int i = first; i < last; i++) {
      for (int j = i + 1; j <= last; j++) {
        if (ans > (i * j) % 2019) {
          ans = (i * j) % 2019;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
