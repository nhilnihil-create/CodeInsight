#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int X, Y;
  cin >> X >> Y;
  long long money = 0;
  money += max(0, (4 - X) * 100000);
  money += max(0, (4 - Y) * 100000);
  money += (X == 1 && Y == 1) ? 400000 : 0;
  cout << money << endl;
  return 0;
}