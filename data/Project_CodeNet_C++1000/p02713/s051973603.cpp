#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll memo[300][300];

int gcd(int x, int y) {
  if (memo[x][y] != 0) return memo[x][y];
  if (y == 0) {
    memo[x][y] = x;
    return x;
  }
  memo[x][y] = gcd(y, x % y);
  return memo[x][y];
}

int main() {
  int k;
  cin >> k;
  ll ans = 0;
  for (int i = k; i >= 1; i--) {
    for (int j = k; j >= 1; j--) {
      for (int l = k; l >= 1; l--) {
        ans += gcd(i, gcd(j, l));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
