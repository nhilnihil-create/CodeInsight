#include <bits/stdc++.h>
#include <bits/stdint-uintn.h>
#include <cstdint>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int64_t attack(int64_t x) {
  if (x == 1) {
    return 1;
  }
  return attack(x / 2) * 2 + 1;
}

int main() {
  uint64_t h;
  std::cin >> h;

  std::cout << attack(h) << std::endl;
  return 0;
}
