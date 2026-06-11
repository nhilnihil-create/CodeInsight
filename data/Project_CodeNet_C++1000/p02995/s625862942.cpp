#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

int get(int a, int b, int x) {
  int l = ((a - 1) / x + 1) * x;
  int r = b / x * x;
  return (r - l) / x + 1;
}

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

void MAIN() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (b - a + 1) - get(a, b, c) - get(a, b, d) + get(a, b, lcm(c, d)) << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
