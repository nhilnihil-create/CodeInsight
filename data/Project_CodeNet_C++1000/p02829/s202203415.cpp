#include <iostream>

using namespace std;

int main(void)
{
 int A,B;
  int ans;
  cin >> A >> B;
  for(int i=1 ;i <=3;i++)
  {
    if(A != i && B != i)
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}