#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

vector<int64_t> divisor(int64_t n) {
  vector<int64_t> ret;
  for (int64_t i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N;
  cin >> N;
  int64_t answer = divisor(N - 1).size() - 1L;
  for (auto div : divisor(N)) {
    if (div == 1) continue;
    int64_t N0 = N;
    while (N0 % div == 0) {
      N0 /= div;
    }
    if (N0 % div == 1) ++answer;
  }
  cout << answer << endl;
  return 0;
}
