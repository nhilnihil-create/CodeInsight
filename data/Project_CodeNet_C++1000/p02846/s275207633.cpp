#include <bits/stdc++.h>

#define rep(i, n) for(int (i) = 0; i < (n); ++(i))

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  ll T1, T2, A1, A2, B1, B2;
  std::cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  ll P, Q;
  P = T1 * (A1 - B1);
  Q = T2 * (A2 - B2);
  if(P > 0) {
    P = -P;
    Q = -Q;
  }

  if(P + Q < 0) {
    std::cout << "0" << '\n';
    return 0;
  }
  if(P + Q == 0) {
    std::cout << "infinity" << '\n';
    return 0;
  }

  ll S = - P / (P + Q);
  ll T = - P % (P + Q);

  ll ans = 2 * S;
  if(T > 0) {
    ++ans;
  }

  std::cout << ans << '\n';
}
