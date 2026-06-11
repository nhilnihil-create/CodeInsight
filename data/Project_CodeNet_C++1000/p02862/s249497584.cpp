#include <bits/stdc++.h>
using namespace std;

int64_t f(int64_t k, int64_t x) {
  if(x == 1) {
    return k % 1000000007;
  }
  else if(x % 2 == 0) {
    int64_t ans = (f(k, x / 2) * f(k, x / 2)) % 1000000007;
    return ans;
  }
  else {
    int64_t ans = (f(k, x / 2) * f(k, x / 2)) % 1000000007;
    ans *= k;
    ans %= 1000000007;
    return ans;
  }
}
    

int main() {
  int X, Y;
  cin >> X >> Y;
  if((X + Y) % 3 != 0 || 2 * Y - X < 0 || 2 * X - Y < 0) {
    cout << 0 << endl;
  }
  else {
    int a = (X + Y) /3;
    int b = (2 * X - Y) / 3;
    int64_t ans = 1;
    for(int i = 0; i < b; i++) {
      ans *= a - i;
      ans %= 1000000007;
    }
    int64_t k = 1;
    for(int i = 0; i < b; i++) {
      k *= i + 1;
      k %= 1000000007;
    }
    int64_t c = f(k, 1000000005);
    ans *= c;
    ans %= 1000000007;
    cout << ans << endl;
  }
}