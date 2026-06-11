#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll h;
  cin >> h;
  int cnt = 0;
  while (h) {
    h /= 2;
    cnt++;
  }
  ll ans = 1;
  rep(i, cnt) ans *= 2;
  cout << ans - 1 << endl;
  return 0;
}
