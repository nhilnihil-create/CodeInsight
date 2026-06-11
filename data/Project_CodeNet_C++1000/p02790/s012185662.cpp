#include <string>
#include <iostream>
using namespace std;

int main() {
  char a, b;
  cin >> a >> b;
  string A(b - '0', a), B(a - '0', b);
  cout << (A < B ? A : B) << endl;
  return 0;
}