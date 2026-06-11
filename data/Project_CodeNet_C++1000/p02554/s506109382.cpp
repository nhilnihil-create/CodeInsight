#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  uint64_t a[3] = {1, 0, 0, };
  uint64_t b[3];
  uint64_t n;
  const uint64_t mod = 1'000'000'007;
  cin >> n;
  for (uint64_t i = 0; i < n; ++i) {
    b[0] = (a[0] * 8) % mod;
    b[1] = (a[0] + a[1] * 9) % mod;
    b[2] = (a[1] * 2 + a[2] * 10) % mod;
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
  }

  cout << a[2] << endl;
}
