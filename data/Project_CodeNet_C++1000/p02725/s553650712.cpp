#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t K, N;

  cin >> K >> N;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int64_t m = 0;
  int64_t start = -1;
  for (int64_t i = 1; i < N; i++) {
    if (m < A.at(i) - A.at(i - 1)) {
      m = A.at(i) - A.at(i - 1);
    }
  }
  if (m < A.at(0) + K - A.at(N - 1)) {
    m = A.at(0) + K - A.at(N - 1);
  }
  cout << K - m;

  return 0;
}
