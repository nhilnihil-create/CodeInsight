#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < 1000; i++) {
    if (i*(a-1)+1 >= b) {
      cout << i << endl;
      return 0;
    }
  }
}
