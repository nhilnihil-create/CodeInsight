#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  
  for (int d = 0; d < 100; d++) {
    if (find(p, p + n, x - d) != p + n) {
      if (find(p, p + n, x + d) != p + n) {
        continue;
      } else {
        cout << x + d;
        return 0;
      }
    } else {
      cout << x - d;
      return 0;
    }
  }
  
  return 0;
}