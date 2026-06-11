#include <iostream>
#include <iomanip>
#include <cmath>
double PI= 3.1415926535897932384626433832;
using namespace std;
int main()
{
    double a,b,C;
    cin>>a>>b>>C;
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<0.5*a*b*sin(C*PI/180)<<endl<<a+b+sqrt(a*a+b*b-2*a*b*cos(C*PI/180))<<endl<<b*sin(C*PI/180)<<endl;
    return 0;
}
