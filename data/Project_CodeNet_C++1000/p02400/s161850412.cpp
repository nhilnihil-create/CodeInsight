#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
 double r;
 double area;
 double length;

 cin >> r;

 area = M_PI * r * r;
 length = M_PI * 2 * r;

 printf("%f%s%f\n", area, " ",length );
 return 0;
}