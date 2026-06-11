#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n % 2 == 1) {
    for (int i = 0; i < m; i++) {
      cout << i + 1 << " " << n - i << endl;
    }
  } else {
    for (int i = 0; i < m; i++) {
      cout << i + 1 << " " << n - i - (2 * i >= m) << endl;
    }
  }
  return 0;
}