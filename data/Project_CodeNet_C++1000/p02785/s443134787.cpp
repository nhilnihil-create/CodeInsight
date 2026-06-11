#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> Hs(N);
  for (int64_t n = 0; n < N; ++n) {
    cin >> Hs[n];
  }
  sort(Hs.begin(), Hs.end());
  
  int64_t attack = 0;
  for (int64_t n = 0; n < N - K; ++n) {
    attack += Hs[n];
  }
  cout << attack << endl;
  
  return 0;
}
