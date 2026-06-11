#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int64_t N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  reverse(T.begin(), T.end());
  int64_t point = 0;
  for (int64_t k = 0; k < K; ++k) {
    int64_t idx = k;
    char pre = '-';
    while (idx < N) {
      if (T[idx] == 'r' && pre != 'r') {
        point += P;
        pre = T[idx];
      } else if (T[idx] == 's' && pre != 's') {
        point += R;
        pre = T[idx];
      } else if (T[idx] == 'p' && pre != 'p') {
        point += S;
        pre = T[idx];
      } else {
        pre = '-';
      }
      idx += K;
    }
  }
  cout << point << endl;
  
  return 0;
}
