#include <bits/stdc++.h>
int main() {
  int n; std::cin >> n;
  int prev = 0;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int t; std::cin >> t;
    if (t < prev) res += prev - t;
    else prev = t;
  }
  std::cout << res;
}
