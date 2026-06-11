#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int64_t n;
  cin >> n;
  map<int64_t, int> m;
  for (int64_t i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      m[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    m[n] = 1;
  }
  int ans = 0;
  for (auto p : m) {
    auto v = p.second;
    int b = 1;
    while (b <= v) {
      v -= b;
      b++;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
