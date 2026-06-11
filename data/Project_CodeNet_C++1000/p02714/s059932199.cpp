#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int64_t R = 0, B = 0, G = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R') {
      R++;
    }
    else if (S.at(i) == 'B') {
      B++;
    }
    else {
      G++;
    }
  }
  int64_t ans = R * B * G;
  for (int i = 0; i < N; i++) {
    for (int j =  i + 1; j < N; j++) {
      int k = 2 * j - i;
      if (k < N) {
        if (S.at(i) != S.at(k) && S.at(j) != S.at(i) && S.at(k) != S.at(j)) {
          ans--;
        }
      }
    }
  }
  cout << ans << endl;
}