#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  rep(i, N) cin >> A[i] >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int64_t midA, midB;
  if (N % 2) {
    midA = A[N / 2];
    midB = B[N / 2];
  } else {
    midA = (A[N / 2 - 1] + A[N / 2]);
    midB = (B[N / 2 - 1] + B[N / 2]);
  }
  int64_t answer = midB - midA + 1L;
  cout << answer << endl;
  return 0;
}
