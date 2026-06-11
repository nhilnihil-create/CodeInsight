#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

 int a;
 int b;
 int d;
 int r;
 double f;

 cin >> a >> b;

 d = a / b;
 r = a % b;

 double x = static_cast<double>(a);
 double y = static_cast<double>(b);

 f = x / y;

 printf("%d%s%d%s%f\n", d," ", r, " ", f);

}