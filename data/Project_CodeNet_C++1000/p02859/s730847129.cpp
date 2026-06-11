#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll r) {
  cout << r*r << endl;
}

int main() {
  ll r;
  cin >> r;
  solve(r);
  return 0;
}
