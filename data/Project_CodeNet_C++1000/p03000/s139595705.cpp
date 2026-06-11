// https://atcoder.jp/contests/abc130/tasks/abc130_b
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
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for (auto &x : L) {
    cin >> x;
  }
  int tmp{}, cnt{};
  REP(i, N) {
    tmp += L[i];
    if (tmp <= X) {
      cnt++;
    }
  }
  cout << cnt + 1 << endl;
  return 0;
}