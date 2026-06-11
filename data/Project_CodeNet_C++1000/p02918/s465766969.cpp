#include <iostream>
#include <string>

int N, K;
std::string S;

int main() {
  std::cin >> N >> K;
  std::cin >> S;
  int cnt_l = 0, cnt_r = 0, cnt_same = 0;
  (S[0] == 'L' ? cnt_l : cnt_r)++;
  for (int i = 1; i < N; ++i) {
    (S[i] == 'L' ? cnt_l : cnt_r)++;
    if (S[i] == S[i-1]) cnt_same++;
  }

  int cnt_pos = (cnt_l-1) + (cnt_r-1);
  std::cout << std::min(N-1, cnt_same + 2*K) << "\n";

  return 0;
}
