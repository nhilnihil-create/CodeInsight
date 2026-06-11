#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}

int main() {
  Int n;
  cin >> n;
  vector<Int> as(n);
  for (Int i = 0; i < n; i++) cin >> as[i];
  Int sum = 0;
  for (Int i = 0; i < n; i++) {
    if (~i & 1)
      sum += as[i];
    else
      sum -= as[i];
  }
  vector<Int> bs(n);
  bs[0] = sum;
  for (Int i = 1; i < n; i++) bs[i] = (as[i - 1] - bs[i - 1] / 2) * 2;
  for (Int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << bs[i];
  }
  cout << endl;
  return 0;
}
