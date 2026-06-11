#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  long long h, w;
  std::cin >> h >> w;

  if (h == 1 || w == 1) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << (h * w + 1) / 2 << std::endl;
  }
  return 0;
}
