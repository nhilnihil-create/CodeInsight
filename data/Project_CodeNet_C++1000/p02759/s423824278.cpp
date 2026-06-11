#include <iostream>

using namespace std;

int main(void)
{
  int X;
  cin >> X;
  int iBuf;
  int ans;
  iBuf = X %2;
  ans = X /2;
  if(iBuf == 1)
  {
    cout << ans+1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}