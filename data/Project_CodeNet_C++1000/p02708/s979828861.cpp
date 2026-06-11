#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int64_t mod = 1e9 + 7;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, K;
  cin >> N >> K;

  int64_t answer = 1;
  int64_t min_num = 0;
  int64_t max_num = 0;
  for (int i = 0; i < K; ++i) {
    min_num += i;
    max_num += (N - i);
  }
  for (int i = K; i <= N; ++i) {
    answer = (answer + max_num - min_num + 1) % mod;
    min_num += i;
    max_num += (N - i);
  }
  cout << answer << endl;
  return 0;
}
