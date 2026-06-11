#include <iostream>

using namespace std;

int main() {
  int k;
  cin >> k;

  int a = 7 % k;
  for (int i = 0; i < k; ++i) {
    if (a == 0) {
      cout << i + 1 << endl;
      return 0;
    }
    a = (a * 10 + 7) % k;
  }
  cout << -1 << endl;
}
