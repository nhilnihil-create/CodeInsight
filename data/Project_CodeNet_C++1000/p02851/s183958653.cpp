#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i + 1];
  }
  vector<int> B(N + 1);
  B[0] = A[0];
  for (int i = 1; i < N + 1; i++) {
    B[i] = B[i - 1] + A[i];
    B[i] %= K;
  }
  for (int i = 0; i < N + 1; i++) {
    B[i] -= i;
    B[i] %= K;
    if (B[i] < 0) {
      B[i] += K;
    }
  }

  map<int, int> m;
  long long ans = 0;
  for (int i = 0; i < N + 1; i++) {
    if (i - K >= 0) {
      m[B[i - K]]--;
    }
    ans += m[B[i]];
    m[B[i]]++;
  }
  cout << ans << endl;

  return 0;
}
