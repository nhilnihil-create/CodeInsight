#include <iostream>
using namespace std;
int main()
{
  int t;
  int h,m,s;
  cin >> t;
  s = t % 60;
  int r = (t - s) / 60;
  m = r % 60;
  r = (r - m) / 60;
  cout << r << ":" << m << ":" << s << endl;
  return 0;
}