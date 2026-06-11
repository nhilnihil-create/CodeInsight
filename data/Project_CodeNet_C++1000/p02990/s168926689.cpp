#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000000 + 7;

int64_t f1(int64_t X, int64_t a) {
  if(a == 0) {
    return 1;
  }
  else if(a % 2 == 0) {
    int64_t ans = f1(X, a / 2) * f1(X, a / 2);
    ans %= MOD;
    return ans;
  }
  else {
    int64_t ans = f1(X, a / 2) * f1(X, a / 2);
    ans %= MOD;
    ans *= X;
    ans %= MOD;
    return ans;
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  for(int i = 1; i <= K; i++) {
    if(N - K < i - 1) {
      cout << 0 << endl;
    }
    else {
      int64_t ans = 1;
      for(int64_t j = 1; j <= i - 1; j++) {
        ans *= K - j;
        ans %= MOD;
      }
      int64_t X = 1;
      for(int64_t j = 1; j <=  i - 1; j++) {
        X *=  j;
        X %= MOD;
      }
      ans *= f1(X, MOD - 2);
      ans %= MOD;
      for(int64_t j = 0; j < i; j++) {
        ans *= N - K + 1 - j;
        ans %= MOD;
      }
      int64_t Y = 1;
      for(int64_t j = 1; j <= i; j++) {
        Y *= j;
        Y %= MOD;
      }
      ans *= f1(Y, MOD - 2);
      ans %= MOD;
      cout << ans << endl;
    }
  }
}
