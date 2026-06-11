#include <bits/stdc++.h>

int main() {
  long long n, a, b;
  std::cin >> n >> a >> b;

  long long cnt = 0;

  cnt += (n / (a + b)) * a;
  cnt += std::min(n % (a + b), a);

  std::cout << cnt << std::endl;
}
