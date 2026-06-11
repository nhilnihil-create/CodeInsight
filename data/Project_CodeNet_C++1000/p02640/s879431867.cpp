#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  puts((y & 1 || y < 2 * x || y > 4 * x) ? "No" : "Yes");
}
