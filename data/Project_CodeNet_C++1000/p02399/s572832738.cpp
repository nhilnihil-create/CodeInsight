#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
 int a, b;
 int d, r;
 double f;
 scanf("%d %d", &a, &b);

 d = a / b;
 r = a % b;
 f = (double)a / b;
 cout << d << " " << r << " ";
 cout << fixed << setprecision(5) << f << endl;
}
