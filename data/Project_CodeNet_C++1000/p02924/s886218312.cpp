#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  rep(i, n) ans += i;
  cout << ans << endl;
  return 0;
}
