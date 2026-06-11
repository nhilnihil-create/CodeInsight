#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int avg = sum / n;
  int avg2 = avg + 1;
  int res = 0;
  int res2 = 0;
  for (int i = 0; i < n; ++i) {
    res += (a[i] - avg) * (a[i] - avg);
    res2 += (a[i] - avg2) * (a[i] - avg2);
  }
  if (res < res2) cout << res << '\n';
  else cout << res2 << '\n';
  return 0;
}
// x^2 - 2px + p^2 => sum(p^2 - 2px) = n p^2 - 2p * sum(x)
