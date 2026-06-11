#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll L) {
  auto mi = L;
  auto ma = L+N-1;

  auto ans = (2*L+N-1)*N/2;
  if (mi < 0 && ma < 0) {
    ans -= ma;
  } else if (mi > 0 && ma > 0) {
    ans -= mi;
  }
  cout << ans << endl;
}

int main() {
  ll N;
  cin >> N;
  ll L;
  cin >> L;
  solve(N, L);
  return 0;
}
