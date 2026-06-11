#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
  double r;
  double PI = 3.1415926535897;
  cin >> r;
  printf("%lf %lf\n", PI * r * r, PI * r * 2);
  return 0;
}