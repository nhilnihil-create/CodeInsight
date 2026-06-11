#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, a, b, c;
  cin >> n;
  for (int i = 1; i < n; ++i) ans += (n - 1) / i;

  cout << ans << endl;
  return 0;
}