#include <iostream>
using namespace std;
int main() {
  long long x;
  cin >> x;
  for (long long a = -118; a <= 119; ++a) {
    for (long long b = -119; b <= 118; ++b) {
      if (a * a * a * a * a - b * b * b * b * b == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}
