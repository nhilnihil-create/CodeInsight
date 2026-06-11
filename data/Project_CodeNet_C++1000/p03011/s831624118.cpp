#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll P, ll Q, ll R) {
  cout << P + Q + R - max({P,Q,R}) << endl;
}

int main() {
  ll P;
  cin >> P;
  ll Q;
  cin >> Q;
  ll R;
  cin >> R;
  solve(P, Q, R);
  return 0;
}
