#include <iostream>
using namespace std;

int main() {
  int a, b;
  for (int i=11;i<100;i++) {
    a = i / 10;
    b = i % 10;
    if (b != 0) {
      cout << a << "x" << b << "=" << a * b << endl;
    }
  }
  return 0;
}