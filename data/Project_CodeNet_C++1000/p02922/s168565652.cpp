#include <iostream>
using namespace std;

int main()
{
  int a, b, ans = 0, socket = 1;
  cin >> a >> b;
  
  while(b - socket > 0)
  {
    socket += a - 1;
    ans++;
  }
  
  cout << ans << endl;
  return 0;
}