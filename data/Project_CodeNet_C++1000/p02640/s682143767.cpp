#include <iostream>
using namespace std;

int main() {
  int X;
  int Y;
  cin >> X >> Y;

  for (int i = 0; i <= X; i++) {
    if (2 * i + 4 * (X - i) == Y) {
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
}