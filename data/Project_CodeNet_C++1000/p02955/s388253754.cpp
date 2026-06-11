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
      ret.emplace_back(i);
      if (i * i != n) ret.emplace_back(n / i);
    }
  }
  sort(ret.rbegin(), ret.rend());
  return (ret);
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  int64_t K;
  cin >> N >> K;
  vector<int64_t> A(N);
  int64_t sum = 0;
  rep(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  int64_t answer = 0;
  for (auto tmp_ans : divisor(sum)) {
    vector<int64_t> mod(N);
    rep(i, N) mod[i] = A[i] % tmp_ans;
    sort(mod.begin(), mod.end());

    vector<int64_t> ssum(N + 1);
    ssum[0] = 0;
    rep(i, N) { ssum[i + 1] = ssum[i] + mod[i]; }

    rep(i, N) {
      int64_t tmp = (N - i) * 1LL * tmp_ans - (ssum[N] - ssum[i]);
      if (max(ssum[i], tmp) <= K) {
        answer = max(answer, tmp_ans);
        break;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
