#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int64_t mod = 998244353;
int64_t power(int64_t n, int64_t m) {
  // cout << n << "^" << m << "=";
  int64_t ret = 1;
  while (m) {
    if (m % 2) {
      ret = (ret * n) % mod;
    }
    n = (n * n) % mod;
    m /= 2;
  }
  // cout << ret << endl;
  return ret;
}

int main(void) {
  int N;
  cin >> N;
  vector<int> D(N);
  int first;
  rep(i, N) {
    int d;
    cin >> d;
    D[d]++;
    if (i == 0) {
      first = d;
    }
  }
  if (D[0] != 1 || first != 0) {
    cout << 0 << endl;
    return 0;
  }
  int last = N - 1;
  while (D[last] == 0) --last;

#ifdef DEBUG
  rep(i, N) { cout << D[i] << " "; }
  cout << endl;
#endif
  int64_t answer = 1;
  for (int i = 2; i <= last; ++i) {
    int64_t times = power(D[i - 1], D[i]);
    answer = (answer * times) % mod;
  }
  cout << answer << endl;
  return 0;
}