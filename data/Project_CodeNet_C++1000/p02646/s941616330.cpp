// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B, V, W, T;
  string ans;
  cin >> A >> V >> B >> W >> T;

  if (V == W) {
    ans = "NO";
  } else {
    if (abs(A - B) > T * (V - W))
      ans = "NO";
    else
      ans = "YES";
  }

  cout << ans << endl;
  return 0;
}
