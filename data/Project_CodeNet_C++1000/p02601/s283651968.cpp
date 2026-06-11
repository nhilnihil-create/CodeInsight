#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= K; k++) {
        int a = A * (1 << i);
        int b = B * (1 << j);
        int c = C * (1 << k);
        if (i + j + k <= K && a < b && b < c) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;

  return 0;
}