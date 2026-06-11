#include<iostream>
using namespace std;

int main()
{
  long long a;
  double b;

  cin >> a >> b;

  long long ib;
  ib = b * 100 + 0.5;
  a *= ib;
  a /= 100;

  cout << a;

  return 0;
}
