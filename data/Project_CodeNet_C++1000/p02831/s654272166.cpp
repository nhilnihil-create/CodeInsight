#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  long long a, b;
  cin >> a >> b;
  if (a < b) {
    swap(a, b);
  }
  long long ret = a * b / __gcd(a, b);
  cout << ret << endl;
  return 0;
}
