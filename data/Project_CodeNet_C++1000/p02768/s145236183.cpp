#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL mpo(LL a, LL n, LL m) {
  LL ret = 1;
  LL kj = 2ll;
  while (n) {
    if (n % kj) ret *= a;
    a = a * a;
    a %= m;
    ret %= m;
    n /= kj;
  }
  return ret;
}
int main () {
  LL n, a, b;
  cin >> n >> a >> b;
  LL m = 1e9 + 7;
  LL ans = mpo(2, n, m);
  LL kj = 1;
  for (LL i = 1; i <= b; i ++) {
    kj *= i;
    kj %= m;
  }
  kj = mpo(kj, m - 2, m);
  LL kja = kj;
  for (LL i = a + 1; i <= b; i ++) {
    kja *= i;
    kja %= m;
  }
  for (LL i = 0ll; i < a; i ++) {
    kja *= (n - i);
    kja %= m;
  }
  for (LL i = 0ll; i < b; i ++) {
    kj *= (n - i);
    kj %= m;
  }
  ans = ans - kj - kja - 1;
  while (ans < 0) ans += m;
  cout << ans << endl;
}

