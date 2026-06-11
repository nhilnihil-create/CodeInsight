#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd2(int a, int b) {
  if (b == 0) return a;
  return gcd2(b, a%b);
}

int gcd3(int a, int b, int c) {
  return gcd2(gcd2(a, b), c);
}

int main() {
  int k;
  cin >> k;
  int ans = 0;
  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) {
        ans += gcd3(a, b, c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}