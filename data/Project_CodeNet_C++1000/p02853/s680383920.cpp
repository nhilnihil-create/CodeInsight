#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_P = 300000;

int main() {
  int X, Y; cin >> X >> Y;
  int ans = 0;
  if(X == 1 && Y == 1) ans += 400000;
  ans += max(MAX_P - 100000*(X-1), 0);
  ans += max(MAX_P - 100000*(Y-1), 0);
  cout << ans << endl;
  return 0;
}
