#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int a, b, c, d, r;
  double f;

  cin >> a >> b;

  d = a/b;
  r = a%b;
  f =(double)a/b;

  printf("%d %d %.5lf", d, r, f);

  return 0;
}