#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;
  if (x < 100) {
    cout << 0 << '\n';
    return 0;
  }

  int cnt = x / 100;
  cout << (x % 100 <= 5 * cnt) << '\n';
}
