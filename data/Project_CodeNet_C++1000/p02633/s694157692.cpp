#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int X;
  cin >> X;

  for (int K = 1;; K++) {
    if ((X * K) % 360 == 0) {
      cout << K << "\n";
      return 0;
    }
  }
}
