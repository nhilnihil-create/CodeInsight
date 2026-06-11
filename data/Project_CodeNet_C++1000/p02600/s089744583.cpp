#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  cin >> x;

  for (int i = 600; i <= 2000; i += 200) {
    if (x < i) {
      cout << 11 - i / 200 << '\n';
      break;
    }
  }

  return 0;
}
