#include <bits/stdc++.h>

using namespace std;

const int BITS = 20;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1) {
        cout << ' ';
      }
      for (int k = 0; k < BITS; k++) {
        if ((i & (1 << k)) != (j & (1 << k))) {
          cout << k + 1;
          break;
        }
      }
    }
    cout << '\n';
  }

  return 0;
}