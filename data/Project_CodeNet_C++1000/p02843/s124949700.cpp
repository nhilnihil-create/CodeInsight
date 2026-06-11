#include <iostream>
#include <vector>

using namespace std;

int main() {
  int X;
  cin >> X;
  int result = 0;
  if (100 <= X) {
    vector<bool> b(X + 6, false);
    b[0] = true;
    for (int i = 0; i <= X - 100; ++i) {
      if (b[i]) {
        b[i + 100] = b[i + 101] = b[i + 102] =
          b[i + 103] = b[i + 104] = b[i + 105] = true;
      }
    }
    result = b[X];
  }
  cout << result << endl;
  return 0;
}
