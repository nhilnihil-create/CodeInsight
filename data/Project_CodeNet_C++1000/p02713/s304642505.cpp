#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= n; k++) {
        ans += gcd(gcd(i, j), k);
      }
    }
  }
  cout << ans;
}
