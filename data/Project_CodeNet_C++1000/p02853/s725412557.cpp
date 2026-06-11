#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, y;
  cin >> x >> y;
  int win[4] = {300000, 200000, 100000, 400000};
  int money = 0;
  if (x <= 3) money += win[x-1];
  if (y <= 3) money += win[y-1];
  if (x * y == 1) money += win[3];
  cout << money << endl;
  return 0;
}