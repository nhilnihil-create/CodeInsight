#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t A, B;
  cin >> A >> B;
  int64_t G = gcd(A, B);
  int64_t M = G;
  int ans = 1;
  for (int i = 2; i <= sqrt(M); i++) {
    if (G % i == 0) {
      ans++;
      while (G % i == 0) {
        G /= i;
      }
    }
  }
  if (G != 1) {
    ans++;
  }
  cout << ans << endl;
}