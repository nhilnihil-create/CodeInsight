#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000;

typedef long long ll;
typedef unsigned long long ull;

ull powMod(ull x, ull n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  ull tmp = powMod(x, n / 2);
  if (n % 2 == 0) return (tmp * tmp) % MOD;
  return x * (tmp * tmp) % MOD;
}

int main(void) {
  int m; cin >> m;
  ll c, d, D = 0, S = 0;
  rep(i, m) {
    cin >> d >> c;
    D += c;
    S += d * c;
  }
  if (S % 9 == 0) cout << (S / 9 - 1) + (D - 1) << endl;
  else cout << S / 9 + D - 1 << endl;

  return 0;
}
  
