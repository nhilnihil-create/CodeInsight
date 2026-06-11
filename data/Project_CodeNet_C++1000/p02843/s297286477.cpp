#include <bits/stdc++.h>
using namespace std;
#define rep(i) for (int i = 1; i < 20; ++i)
using ll = long long;
using P = pair<int, int>;

int x;
bool ans = false;

int main() {
  cin >> x;
  rep (i) {
    if (100*i <= x && x <= 100*i + 5*i) ans = true;
  }
  if (2000 <= x) ans = true;
  cout << ans << endl;
  return 0;
}
