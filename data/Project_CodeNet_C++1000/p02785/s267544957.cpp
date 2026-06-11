#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> h(n);

  for (long long& hi : h) {
    cin >> hi;
  }

  sort(h.begin(), h.end(), greater<>());

  long long ret = 0;
  for (int i = k; i < n; ++i) {
    ret += h[i];
  }
  cout << ret << endl;
  return 0;
}
