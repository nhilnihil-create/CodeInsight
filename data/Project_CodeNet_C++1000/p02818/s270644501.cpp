#include <iostream>
#include <string>

using namespace std;

int main()
{
  int64_t a, b, k;
  cin >> a >> b >> k;

  int64_t t  = a - k > 0 ? a - k : 0;
  int64_t ao = b - (k - a) > 0 ? b - (k - a) : 0;

  if (a - k > 0)
  {
    t  = a - k;
    ao = b;
  }
  else
  {
    t  = 0;
    ao = b - (k - a) > 0 ? b - (k - a) : 0;
  }

  cout << t << " " << ao << endl;

  return 0;
}