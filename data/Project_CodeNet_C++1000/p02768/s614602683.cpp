#include <bits/stdc++.h>
using namespace std;

int64_t f1(int n, int64_t i) {
  if(n == 0) {
    return 1;
  }
  else if(n % 2 == 0) {
    int64_t a = f1(n / 2, i);
    a = (a * a) % 1000000007;
    return a;
  }
  else {
    int64_t a = f1(n / 2, i);
    a = (a * a) % 1000000007;
    a = a * i % 1000000007;
    return a;
  }
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int64_t A = 1;
  for(int i = 0; i < a; i++) {
    A *= i + 1;
    A %= 1000000007;
  }
  A = f1(1000000005, A);
  for(int i = 0; i < a; i++) {
    A *= n - i;
    A %= 1000000007;
  }
  int64_t B = 1;
  for(int i = 0; i < b; i++) {
    B *= i + 1;
    B %= 1000000007;
  }
  B = f1(1000000005, B);
  for(int i = 0; i < b; i++) {
    B *= n - i;
    B %= 1000000007;
  }
  int64_t ans = f1(n, 2) - 1 - A - B;
  ans %= 1000000007;
  if(ans >= 0) {
    cout << ans << endl;
  }
  else {
    cout << ans + 1000000007 << endl;
  }
}