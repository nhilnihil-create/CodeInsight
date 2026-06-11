#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll D) {
  cout << (N-1)/(2*D+1)+1 << endl;
}

int main() {
  ll N;
  cin >> N;
  ll D;
  cin >> D;
  solve(N, D);
  return 0;
}
