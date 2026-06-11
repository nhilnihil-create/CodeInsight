#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int N = S.size();
  int64_t K;
  cin >> K;

  int64_t left_num = 1;
  for (int i = 1; i < N; ++i) {
    if (S[0] != S[i]) break;
    ++left_num;
  }
  if (left_num == N) {  // All number is the same
    cout << N * K / 2 << endl;
    return 0;
  }

  int64_t right_num = 1;
  for (int i = N - 2; i >= 0; --i) {
    if (S[N - 1] != S[i]) break;
    ++right_num;
  }

  int64_t answer = 0;
  int64_t seq_num = 1;
  for (int i = 1; i < N; ++i) {
    if (S[i - 1] == S[i]) {
      ++seq_num;
    } else {
      answer += (seq_num / 2);
      seq_num = 1;
    }
  }
  answer += (seq_num / 2);
  answer *= K;

  if (S[0] == S[N - 1]) {
    answer += (left_num + right_num) / 2 * (K - 1);
    answer -= left_num / 2 * (K - 1);
    answer -= right_num / 2 * (K - 1);
  }
  cout << answer << endl;
  return 0;
}