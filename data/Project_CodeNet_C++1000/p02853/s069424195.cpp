#include <bits/stdc++.h>
using namespace std;
int main() {
  int X, Y, Z = 0; cin >> X >> Y;
  cout << (max(4 - X, 0) + max(4 - Y, 0)) * 100000 + ((X + Y == 2) ? 400000 : 0) << endl;
}
