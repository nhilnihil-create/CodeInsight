#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll H, ll W, ll N) {
  auto m = max(H,W);
  auto ans = (N-1)/m+1;
  cout << ans << endl;
}

int main() {
  ll H;
  cin >> H;
  ll W;
  cin >> W;
  ll N;
  cin >> N;
  solve(H, W, N);
  return 0;
}
