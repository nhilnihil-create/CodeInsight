#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n;
  cin >> n;

  int ret = 0;
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    if (ai == cur) {
      ++cur;
    } else {
      ++ret;
    }
  }
  if (ret == n) ret = -1;
  cout << ret << endl;

  return 0;
}
