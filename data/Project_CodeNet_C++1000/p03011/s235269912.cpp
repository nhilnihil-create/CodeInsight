#include<iostream>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if(a >= b && a >= c)
    cout << b + c;
  if(b > a && b >= c)
    cout << a + c;
  if(c > a && c > b)
    cout << a + b;
  return 0;
}