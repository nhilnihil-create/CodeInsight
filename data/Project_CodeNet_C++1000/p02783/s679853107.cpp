#include <iostream>

using namespace std;

int main(void)
{
 int H,A;
  cin >> H>>A;
  int ans;
  int iBuf;
 ans =H/A;
   iBuf = H%A;
  if(iBuf != 0)
  {
  cout << ans+1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}
