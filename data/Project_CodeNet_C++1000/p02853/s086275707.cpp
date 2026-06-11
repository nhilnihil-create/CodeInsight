#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  int ans = (max(4 - X, 0) + max(4 - Y, 0)) * 100000;
  if (X == 1 && Y == 1)
    ans += 400000;
  cout << ans << endl;
}