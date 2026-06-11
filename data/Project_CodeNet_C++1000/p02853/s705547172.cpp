#include <iostream>
using namespace std;

int main() {
  int x, y, point = 0;
  cin >> x >> y;
  if (x == 1) {
    point += 300000;
  }
  else if (x == 2) {
    point += 200000;
  }
  else if (x == 3) {
    point += 100000;
  }
  if (y== 1) {
    point += 300000;
  }
  else if (y ==2) {
    point += 200000;
  }
  else if (y ==3) {
    point += 100000;
  }
  if (x * y == 1) {
    point += 400000;
  }
  cout << point << endl;
}