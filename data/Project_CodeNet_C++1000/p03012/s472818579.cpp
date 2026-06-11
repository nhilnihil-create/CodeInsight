// https://atcoder.jp/contests/abc129/tasks/abc129_b
// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
// clang-format on
int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  for (auto &x : W) {
    cin >> x;
  }
  int res{INT_MAX}, left{}, right{};
  REP(i, N - 1) {
    left = accumulate(W.begin(), W.begin() + 1 + i, 0);
    right = accumulate(W.begin() + i + 1, W.end(), 0);
    res = min(res, abs(left - right));
  }
  cout << res << endl;
  return 0;
}