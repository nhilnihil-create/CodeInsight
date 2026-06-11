#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
  i64 N, K;
  cin >> N >> K;
  vector<i64> H(N);
  for (auto&& x : H) cin >> x;

  sort(H.begin(), H.end());
  i64 res = 0;
  for (int i = 0; i < N - K; i++) {
    res += H[i];
  }
  cout << res << endl;
}