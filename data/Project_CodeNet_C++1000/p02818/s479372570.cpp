#include <bits/stdc++.h>

int main() {
  long a, b, k;
  std::cin >> a;
  std::cin >> b;
  std::cin >> k;

  long takahashi = a;
  long aoki = b;

  if (a < k) {
    takahashi = 0;
    if (a + b < k) {
      aoki = 0;
    } else {
      aoki = b - k + a;
    }
  } else {
    takahashi = a - k;
    aoki = b;
  }
  std::cout << takahashi << " " << aoki << std::endl;
}
