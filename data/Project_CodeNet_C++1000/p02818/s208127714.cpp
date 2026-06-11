#include <iostream>
using namespace std;

int main()
{
  long a, b, k, c, d;
  cin >> a >> b >> k;
  c = (a > k) ? a - k : 0;
  if(!c)
  {
    k -= a;
    d = (b > k) ? b - k : 0;
  }
  else
    d = b;
  
  cout << c << ' ' << d << endl;
  return 0;
}