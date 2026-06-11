/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t a, b, x;
  cin >> a >> b >> x;
  const int64_t temp_1 = (a * a * b - x) * 2;
  const int64_t temp_2 = a * a * a;
  const double tan_theta = static_cast<double>(temp_1) / static_cast<double>(temp_2);
  double result = atan2(static_cast<double>(temp_1), static_cast<double>(temp_2)) / M_PI * 180.0;
  if (a * tan_theta > static_cast<double>(b)) {
    const int64_t temp_3 = b * b * a;
    const int64_t temp_4 = 2 * x;
    result = atan2(static_cast<double>(temp_3), static_cast<double>(temp_4)) / M_PI * 180.0;
  }

  cout << std::setprecision(20) << result << endl;

  return 0;
}
