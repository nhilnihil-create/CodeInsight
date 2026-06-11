#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  long long n;
  cin >> n;

  if (n % 2 == 1) {
    cout << 0 << endl;
  } else {
    long long ret = 0;
    long long den = 10;
    while (den <= n) {
      ret += n / den;
      den *= 5;
    }
    cout << ret << endl;
  }
  return 0;
}
