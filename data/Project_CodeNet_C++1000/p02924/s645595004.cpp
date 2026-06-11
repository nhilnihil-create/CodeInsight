#include <algorithm>
#include <bits/stdc++.h>
#include <bits/stdint-intn.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int64_t n;
  std::cin >> n;

  std::cout << n * (n - 1) / 2 << std::endl;

  return 0;
}
