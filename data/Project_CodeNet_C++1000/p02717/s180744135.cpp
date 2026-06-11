#include <iostream>
using namespace std;

int main(void)
{
  int x,y,z;
  int t=0;
  
  cin >> x >> y >> z;
  
  t = x;
  x = y;
  y = t;
  t = x;
  x = z;
  z = t;
  
  cout << x << " " << y << " " << z <<endl;
  
  return 0;
}