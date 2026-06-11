#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, d, a;
  cin >> n >> d >> a;
  pair<int, int> pairs[n];
  for (int i = 0; cin >> pairs[i].first >> pairs[i].second; ++i) {}
  sort(pairs, pairs + n);
  int64_t diff[n];
  diff[0] = pairs[0].second;
  for (int i = 1; i < n; ++i) {
    diff[i] = pairs[i].second - pairs[i - 1].second;
  }
  int64_t sum = 0, result = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    sum += diff[i];
    if (sum > 0) {
      auto current = (sum - 1) / a + 1;
      result += current;
      sum -= current * a;
      while (j < n && pairs[j].first - d <= pairs[i].first + d) {
        ++j;
      }
      if (j < n) {
        diff[j] += current * a;
      }
    }
  }
  cout << result;
  return 0;
}
