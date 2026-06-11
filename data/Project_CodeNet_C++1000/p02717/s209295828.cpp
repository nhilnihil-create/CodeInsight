#include <iostream>
using namespace std;

void swap()
{
  int a, b, c, temp;
  temp = 0;

  cin >> a >> b >> c;

  temp = b;
  b = a;
  a = temp;

  temp = c;
  c = a;
  a = temp;

  cout << a << " " << b  << " " << c << endl;
}

int main()
{
   swap();
}
