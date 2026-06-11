#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, total = 0;

  cin >> n;

  vector<long> a;

  for (int i = 0; i < n; i++) {
    long tmp;
    cin >> tmp;
    a.push_back(tmp);
    total += tmp;
  }

  long ans = LONG_MAX, tmp = 0;

  for (int i = 0; i < n; i++) {
    tmp += a.at(i);
    total -= a.at(i);
    ans = min(ans, abs(tmp - total));
  }

  cout << ans;

  return 0;
}