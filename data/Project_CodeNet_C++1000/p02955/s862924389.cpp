#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int64_t sum = 0;
  for (auto a : A) {
    sum += a;
  }
  vector<int64_t> divisor;
  for (int64_t i = 1; i * i < sum + 1; i++) {
    if (sum % i == 0) {
      divisor.emplace_back(i);
      divisor.emplace_back(sum / i);
    }
  }
  int64_t res = 0;
  for (auto d : divisor) {
    vector<int64_t> R(N);
    for (int i = 0; i < N; i++) {
      R[i] = A[i] % d;
    }
    sort(R.begin(), R.end());
    vector<int64_t> ACC = {0}, BCC = {0};
    for (auto r : R) {
      ACC.emplace_back(ACC.back() + r);
      BCC.emplace_back(BCC.back() + ((2 * d - r) % d));
    }
    for (int i = 0; i < (int)ACC.size(); i++) {
      if (BCC.back() - BCC[i] == ACC[i] && ACC[i] <= K) {
        res = max(res, d);
      }
    }
  }
  cout << res << '\n';
  return 0;
}
