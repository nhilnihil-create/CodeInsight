#include <iostream>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0;
  } else {
    int64_t result = 0;
    for (int64_t i = 5; i <= n; i *= 5) {
      result += n / i / 2;
    }
    cout << result;
  }
  return 0;
}
