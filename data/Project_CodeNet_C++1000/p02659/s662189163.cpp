#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A;
  double b;
  cin >> A >> b;
  if (A == 0 || b == 0) {
    cout << 0 << endl;
  }
  else {
    int64_t B = b*100+0.5;
    int64_t C = A*B/100;
    cout << C << endl;
  }
}
