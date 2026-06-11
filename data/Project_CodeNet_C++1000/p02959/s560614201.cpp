#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N);
  for (int i = 0; i < N + 1; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    int C = min(A[i], B[i]);
    ans += C, A[i] -= C, B[i] -= C;
    ans += min(A[i + 1], B[i]), A[i + 1] -= min(A[i + 1], B[i]);
  }

  cout << ans << endl;
}
