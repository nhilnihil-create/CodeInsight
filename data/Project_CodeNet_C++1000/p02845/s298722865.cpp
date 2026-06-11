#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
  int n;
  cin >> n;

  ll ans = 1;
  int color[3]{};
  for (int i = 0; i < n; i++) {
    int a = 0;
    cin >> a;
    ll same = 0;
    for (int j = 0; j < 3; j++) {
      if (color[j] == a) {
        if (same == 0) color[j]++;
        same++;
      }
    }
    ans *= same;
    ans %= mod;
    if (ans == 0) break;
  }
  cout << ans << endl;

  return 0;
}