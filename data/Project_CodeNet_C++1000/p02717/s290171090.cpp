#include <iostream>

using namespace std;

int main() {
  int A, B, C, tmp;
  cin >> A;
  cin >> B;
  cin >> C;

  tmp = A;
  A = B;
  B = tmp;

  tmp = A;
  A = C;
  C = tmp;

  cout << A << " " << B << " " << C;

  return 0;
}

