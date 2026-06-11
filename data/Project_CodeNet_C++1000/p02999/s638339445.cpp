#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll X, ll A) {
  cout << (X<A ? 0 : 10) << endl;
}

int main() {
  ll X;
  cin >> X;
  ll A;
  cin >> A;
  solve(X, A);
  return 0;
}
