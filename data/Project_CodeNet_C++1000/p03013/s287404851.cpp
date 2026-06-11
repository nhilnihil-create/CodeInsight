#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t divider = 1000000007;
  
int main() {
  int64_t N, M;
  cin >> N >> M;
  bitset<1000001> steps;
  for (int m = 0; m < M; ++m) {
    int s;
    cin >> s;
    steps.set(s);
    if (steps.test(s - 1)) {
      cout << 0 << endl;
      return 0;
    }
  }
  vector<int64_t> pat(N+1);
  pat[0] = 1;
  for (size_t i = 0; i <= N; ++i) {
    if (!steps.test(i+1)) {
      pat[i+1] = (pat[i+1] + pat[i]) % divider;
    }
    if (!steps.test(i+2)) {
      pat[i+2] = (pat[i+2] + pat[i]) % divider;
    }
  }
  
  cout << pat[N] << endl;
  
  return 0;
}
