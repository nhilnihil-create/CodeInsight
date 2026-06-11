#include <iostream>
using namespace std;
int main() {
  unsigned long long K;
  cin >> K;
  if (K % 2 == 0 || K % 5 == 0) {
    cout << -1;
    return 0;
  }
  unsigned long long x = 7;
  int c = 1;
  while (true) {
    if (x % K == 0) break;
    if (c > K + 2) {
      c = -1;
      break;
    }
    x = (10 * x + 7) % K;
    c++;
  }
  cout << c;
  return 0;
}