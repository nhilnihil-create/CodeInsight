#include <iostream>

using namespace std;

long long pow5(long long x) {
  long long res = 1;
  for (int i = 0; i < 5; i++) {
    res *= x;
  }
  return res;
}

int main() {
  long long x;
  cin >> x;
  for (int a = 0; a <= 500; a++) {
    for (int b = -500; b <= 500; b++) {
      long long tmp = pow5(a) - pow5(b);
      if (tmp == x) {
        cout << a << ' ' << b << endl;
        return 0;
      }
    }
  }
  return 0;
}
