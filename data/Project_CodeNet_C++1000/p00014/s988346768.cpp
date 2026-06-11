#include <iostream>

using namespace std;

int main() {
  int d, tmp, s = 0;
  while (cin >> d) {
    tmp = d;
    for (; d <= 600 - tmp; d += tmp) {
      s += d * d * tmp;
    }
    cout << s << endl;
    s = 0;
  }
  return 0;
}

