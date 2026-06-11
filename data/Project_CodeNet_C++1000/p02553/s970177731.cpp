#include <iostream>
int main() {
  long a, b, c, d;
  long long ans;

  std::cin >> a >> b >> c >> d;
  ans = std::max(a * c, a * d);
  ans = std::max(ans, (long long)b * c);
  ans = std::max(ans, (long long)b * d);

  std::cout << ans << std::endl;

  return 0;
}
