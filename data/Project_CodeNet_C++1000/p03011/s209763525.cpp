#include <iostream>

using namespace std;

int main() {

  int a, b, c;
  string mrPopo;
  cin >> a >> b >> c;
  cout << a + b + c - max(max(a, b), c);
  return 0;
}
