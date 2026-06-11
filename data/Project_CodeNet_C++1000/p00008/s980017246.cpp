#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int sum = 0;
    int cnt = 0;
    for (int a = 0; a < 10; ++a) {
    sum += a;
    for (int b = 0; b < 10; ++b) {
    sum += b;
    for (int c = 0; c < 10; ++c) {
    sum += c;
    for (int d = 0; d < 10; ++d) {
    sum += d;
    if (sum == n) cnt++;
    sum -= d;
    }
    sum -= c;
    }
    sum -= b;
    }
    sum -= a;
    }
    cout << cnt << endl;
  }
  return 0;
}