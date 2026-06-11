#include <iostream>
using namespace std;
int main()
{
  int X;
  cin >> X;
  int ans = 0;
  int ang = 0;
  for (;;) {
    ang = (ang + X) % 360;
    ans++;
    if (ang == 0) break;
  }
  cout << ans << endl;
  return 0;
}
