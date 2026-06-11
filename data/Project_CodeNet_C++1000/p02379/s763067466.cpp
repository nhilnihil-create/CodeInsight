#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
double x1,x2,y1,y2,x,y,a,b,p;

cin >> x1 >> y1 >> x2 >> y2;
x = x2 - x1;
y = y2 - y1;
a = x * x;
b = y * y;
p = a + b;
double answer = sqrt(p);
cout << fixed << setprecision(8) << answer << endl;



}