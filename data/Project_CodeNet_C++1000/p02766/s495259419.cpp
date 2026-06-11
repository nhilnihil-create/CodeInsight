#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> ret;
  while (n) {
    ret.push_back(n % k);
    n /= k;
  }
  cout << ret.size() << endl;

  return 0;
}
