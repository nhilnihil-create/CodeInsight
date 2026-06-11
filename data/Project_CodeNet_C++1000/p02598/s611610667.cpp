#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  auto f = [&](int64_t x) {
    int64_t cnt = 0;
    for (auto a : A) {
      cnt += (a - 1) / x;
    }
    return cnt <= K;
  };
  int64_t lo = 1, hi = *max_element(A.begin(), A.end());
  while (lo < hi) {
    auto mi = (lo + hi) / 2;
    if (f(mi)) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  cout << hi << '\n';
  return 0;
}
