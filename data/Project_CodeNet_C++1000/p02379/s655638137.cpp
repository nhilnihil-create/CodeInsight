#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double x1,y1,x2,y2,a,b,c;
    cin>>x1>>y1>>x2>>y2;
    a = x1 - x2;
    b = y1 - y2;
    c = sqrt(a*a + b*b);
    cout<<fixed;
    cout<<setprecision(8);
    cout<<c;
}
