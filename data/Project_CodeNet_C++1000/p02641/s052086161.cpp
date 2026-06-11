#include <iostream>

using namespace std;

int main() {
  int x, n;
  bool m[105];
  for (bool &i : m) i = true;
  cin >> x >> n;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    m[p] = false;
  }
  for (int i = 0; i < n + 1; ++i) {
    if (m[x - i]) {
      cout << x - i << endl;
      return 0;
    }
    if (m[x + i]) {
      cout << x + i << endl;
      return 0;
    }
  }
}
