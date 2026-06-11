#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int x, y;
  cin >> x >> y;
  int p[] = {300000, 200000, 100000};
  int price = 0;
  if (x <= 3) {
    price += p[x-1];
  }
  if (y <= 3) {
    price += p[y-1];
  }
  if (x == 1 && y == 1) {
    price += 400000;
  }
  cout << price << endl;
  return 0;
}