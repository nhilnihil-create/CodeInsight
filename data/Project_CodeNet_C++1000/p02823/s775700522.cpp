#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, a, b, ans = 0;
  cin >> n >> a >> b;
  if ((b - a) % 2 == 0)
    ans = (b - a) / 2;
  else
    ans = min(a - 1, n - b) + 1 + (b - a - 1) / 2;

  if (a == b) ans = 0;
  cout << ans << endl;
  return 0;
}
