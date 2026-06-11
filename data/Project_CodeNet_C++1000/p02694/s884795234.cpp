#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  ll X;
  cin >> X;

  int ans = 0;
  ll s = 100;
  while (s < X) {
    s += s / 100;
    ans++;
  }

  cout << ans << endl;
  return 0;
}