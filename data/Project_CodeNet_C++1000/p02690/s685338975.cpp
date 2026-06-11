#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int X;
  cin >> X;
  for (int A = -1000; A <= 1000; A++) {
    for (int B = -1000; B <= 1000; B++) {
      if (pow(A, 5) - pow(B, 5) == X) {
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
}