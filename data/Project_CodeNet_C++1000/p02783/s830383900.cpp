#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, A;
  cin >> H >> A;

  int B = 0;
  for (int i = 0; i < 10000; i++) {
    if (H > 0) {
      H -= A;
      B++;
    }
    else break;
  }

  cout << B << endl;
}
