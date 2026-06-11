#include <iostream>
using namespace std;

int main()
{
  int n, x, l, d = 0,cnt = 1;
  cin >> n >> x;
  
  while(cin >> l)
  {
    d += l;
    if(d <= x)
      cnt++;
    else
      break;
  }
  cout << cnt << endl;
  return 0;
}