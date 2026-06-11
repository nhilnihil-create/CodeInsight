#include <iostream>

using namespace std;

int main() {
  int X;
  cin >> X;
  cout << (X % 100 <= X / 100 * 5 ? 1 : 0) << endl;
}
