#include <iostream>

using namespace std;

int main()
{
  int a, b;
  int ans = 0;
  cin >> a >> b;
  
  if (a < 4) ans += (4-a) * 100000;
  if (b < 4) ans += (4-b) * 100000;
  
  if (a == b && a == 1) ans += 400000;
  
  cout << ans << endl;
}