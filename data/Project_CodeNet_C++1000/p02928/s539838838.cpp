#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> A(N);

  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int64_t inner_inv = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      if (A.at(i) > A.at(j)) {
        inner_inv++;
      }
    }
  }

  int64_t outer_inv = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (A.at(i) > A.at(j)) {
        outer_inv++;
      }
    }
  }

  int64_t ans = inner_inv * K % 1000000007; 
  ans += (outer_inv% 1000000007) *( K * (K-1) / 2% 1000000007); 
  ans %= 1000000007; 

  cout << ans; 

  return 0;
}
