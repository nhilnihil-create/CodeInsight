#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  long long h;
  cin >> h;

  long long ret = 0;
  long long iter = 1;
  while (h >= 1) {
    ret += iter;
    iter *= 2;
    h /= 2;
  }
  cout << ret << endl;
  return 0;
}
