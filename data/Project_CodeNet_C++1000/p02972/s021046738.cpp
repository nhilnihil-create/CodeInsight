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
  vector<Int> as(n + 1);
  for (Int i = 1; i <= n; i++) cin >> as[i];

  vector<Int> bs(n + 1, 0), cs;
  for (Int i = n; i >= 1; i--) {
    Int sum = as[i];
    for (Int j = i + i; j <= n; j += i) sum += bs[j];
    bs[i] = sum % 2;
    if (bs[i]) cs.emplace_back(i);
  }

  Int m = cs.size();
  cout << m << endl;
  for (Int i = 0; i < m; i++) {
    if (i) cout << " ";
    cout << cs[i];
  }
  cout << endl;
  return 0;
}
