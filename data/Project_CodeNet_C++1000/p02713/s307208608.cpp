#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int k;
  cin >> k;

  int res = 0;
  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) {
        res += gcd(gcd(a, b), c);
      }
    }
  }
  cout << res << endl;
  return 0;
}