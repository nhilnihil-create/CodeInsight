#include <iostream>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  double t = 0.5 * Y - X;
  double c = 2 * X - 0.5 * Y;
  if (t < 0 || c < 0 || (int)t != t || (int)c != c)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}