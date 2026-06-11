#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<int64_t> A(N);
  rep(i, N) { cin >> A[i]; }
  sort(A.begin(), A.end(), greater<int>());

  int left = P - 1;
  int right = N;
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if ((A[mid] + M) < A[P - 1]) {
      right = mid;
      continue;
    }
    int64_t score = 0;
    score += M * (1 + (P - 1) + (N - mid - 1));
    for (int j = P - 1; j < mid; ++j) {
      if (A[j] < (A[mid] + M)) {
        score += (A[mid] + M - A[j]);
      }
    }
    if (M * V <= score) {
      left = mid;
    } else {
      right = mid;
    }
  }
  int answer = left + 1;
  cout << answer << endl;
  return 0;
}