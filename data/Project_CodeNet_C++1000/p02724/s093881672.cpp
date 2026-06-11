#include <iostream>

using namespace std;

int main(void)
{
  int X;
  int ans;
  cin >> X;
  int iBuf1;
  int iBuf2;
  iBuf1 = X /500;
  iBuf2 = X % 500;
  iBuf2 = iBuf2 /5;
  ans = iBuf1 *1000 + iBuf2*5;
  cout << ans << endl;
  
}
