#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N;
  cin >> N;
  int ans = 0;
  int64_t M = N;
  for (int i = 2; i <= sqrt(M); i++) {
    if (N % i == 0) {
      int64_t k = i; 
      for (int j = 0; j < 45; j++) {
        if (N % k == 0) {
          N /= k;
          ans++;
          k *= i;
        }
        else {
          while (N % i == 0) {
            N /= i;
          }
          break;
        }
      }
    }
  }
  if (N != 1) {
    ans++;
  }
  if (M == N) {
    ans = 1;
  }
  if (M == 1) {
    ans = 0;
  }
  cout << ans << endl;
}