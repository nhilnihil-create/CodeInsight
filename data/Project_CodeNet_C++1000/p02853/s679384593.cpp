#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int a (ll rank) {
  switch(rank) {
    case 1:
      return 300000;
    case 2:
      return 200000;
    case 3:
      return 100000;
  }
  return 0;
}

void solve(ll X, ll Y) {
  auto award = a(X) + a(Y);
  if (X == 1 && Y == 1) {
    award += 400000;
  }
  cout << award << endl;
}

int main() {
  ll X;
  cin >> X;
  ll Y;
  cin >> Y;
  solve(X, Y);
  return 0;
}
