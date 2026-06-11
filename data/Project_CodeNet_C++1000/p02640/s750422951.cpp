#include <iostream>
using namespace std;

int main()
{
  int x, y, z;
  cin >> x >> y;
  z = (4 * x - y) / 2;
  if(0 <= z && z <= x && 2 * z + 4 * (x - z) == y)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}