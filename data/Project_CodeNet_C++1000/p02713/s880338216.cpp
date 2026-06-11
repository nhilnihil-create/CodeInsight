#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int K;
  cin >> K;
  int sum = 0;
  int m = 0;
  for (int a = 1; a <= K; a++) {
    for (int b = 1; b <= K; b++) {
      for (int c = 1; c <= K; c++) {
        m = min({a, b, c});
        int mm = 1;
        for (int k = m; 1 <= k; k--) {
          if (a % k == 0 && b % k == 0 && c % k == 0) {
            mm = k;
            break;
          }
        }
        sum += mm;
      }
    }
  }
  cout << sum << endl;
  return 0;
}