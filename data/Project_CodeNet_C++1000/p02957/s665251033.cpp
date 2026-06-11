#include <bits/stdc++.h>
using namespace std;
int abs(int x) {
  if(x >= 0) {
    return x;
  }
  else {
    return -1 * x;
  }
}
int main() {
  int A, B, C;
  cin >> A >> B;
  C = abs(A - B);
  if(C % 2 == 0) {
    cout << min(A, B) + C / 2;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}
