#include <bits/stdc++.h>
using namespace std;

int64_t f1(int64_t a, int64_t b) {
  if(a % b == 0) {
    return b;
  }
  else {
    return f1(b, a % b);
  }
}

int main() {
  int64_t A, B, C, D;
  cin >> A >> B >> C >> D;
  int64_t x = B / C - A / C;
  if(A % C == 0) {
    x += 1;
  }
  int64_t y = B / D - A / D;
  if(A % D == 0) {
    y += 1;
  }
  int64_t E = C * D / f1(max(C, D), min(C, D));
  int64_t z = B / E - A / E;
  if(A % E == 0) {
    z += 1;
  }
  cout << B - A + 1 - x - y + z << endl;
}
