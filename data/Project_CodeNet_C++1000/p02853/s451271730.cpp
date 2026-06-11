#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int x, y;
  cin >> x >> y;
  int result = 0;
  if (x <= 3) result += (4 - x) * 100 * 1000;
  if (y <= 3) result += (4 - y) * 100 * 1000;
  if (x == 1 && y == 1) result += 400 * 1000;
  cout << result << endl;
  return 0;
}
