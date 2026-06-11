#include <iostream>

using namespace std;

int main() {
  int A, B;
  cin >> A;
  cin >> B;

  for(int i = B * 10, l = (B + 1) * 10; i < l; i++) {
    if((i * 8 / 100) == A) {
      cout << i;
      return 0;
    }
  }

  cout << -1;
  return 0;
}
