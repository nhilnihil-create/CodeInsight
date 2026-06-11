#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end(), greater<long long>());
  long long res = 0;
  for (int i = 0; i + 1 < N; ++i) {
    res += A[(i + 1) / 2];
  }
  cout << res << endl;
}
