#include <iostream>
using namespace std;

int main()
{
  int l, r, d, count;
  count = 0;
  cin >> l >> r >> d;

  for (int i = 0; i < 1000; i+=d)
   {
    if(l <= i && i <= r)
    count++;
   }
  cout << count << endl;
}
