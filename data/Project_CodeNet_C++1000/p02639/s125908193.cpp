#include <iostream>
using namespace std;

int main() {
  int lst[5];
  for (int i = 0; i < 5; i++) {
    cin >> lst[i];
  }

  int x = 1;
  for (int i = 0; i < 5; i++) {
    if (x * lst[i] == 0) {
      cout << i + 1 << endl;
    }
  }
}
