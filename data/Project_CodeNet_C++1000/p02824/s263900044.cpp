#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int64_t n, m, v, p;
  cin >> n >> m >> v >> p;
  int a[n], result = p;
  for (int i = 0; cin >> a[i]; ++i) {}
  sort(a, a + n, greater<int>());
  int64_t sum = 0;
  for (int i = p; i < n; ++i) {
    sum += a[i - 1];
    if (a[i] + m >= a[p - 1] && (i - p + 1) * (a[i] + m) - sum + (p + n - 1 - i) * m >= m * v) {
      ++result;
    }
  }
  cout << result;
  return 0;
}
