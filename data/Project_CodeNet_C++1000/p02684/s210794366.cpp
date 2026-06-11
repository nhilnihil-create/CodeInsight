#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int64_t> memo(N, N + 1);
  int64_t X = 0;
  int64_t Y;
  int64_t Z;
  memo.at(0) = 0;
  for (int64_t i = 0; i < N; i++) {
    if (memo.at(A.at(X) - 1) != N + 1) {
      Y = i - memo.at(A.at(X) - 1) + 1;
      Z = memo.at(A.at(X) - 1);
      break;
    }
    else {
      memo.at(A.at(X) - 1) = i + 1;
      X = A.at(X) - 1;
    }      
  }
  if (K >= Z) {
  for (int64_t i = 0; i < N; i++) {
    if (memo.at(i) == (K - Z) % Y + Z) {
      cout << i + 1 << endl;
      break;
    }
  }
  }
  else {
    int ans = 0;
  for (int i = 0; i < K; i++) {
    ans = A.at(ans) - 1;
  }
  cout << ans + 1 << endl;
  }    
}