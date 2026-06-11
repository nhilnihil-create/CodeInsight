#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N;
  cin >> N;
  int ans = 0;
  int64_t M = N;
  for (int i = 2; i <= sqrt(M); i++) {
    int memo = 0;
    while (N % i == 0) {
      N /= i;
      memo++;
    }
    for (int j = 1; j < 45; j++) {
      if (memo >= j) {
        ans++;
        memo -= j;
      }
      else {
        break;
      }
    }
  }
  if (N != 1) {
    ans++;
  }
  cout << ans << endl;
}
  