#include<iostream>
#include<iomanip>
#include<math.h>

#define PI M_PI

using namespace std;

int main()
{

    double a,b,c;

    cin>>a>>b>>c;

    cout<<fixed<<setprecision(5)<<
    a*b*sin(c*PI/180)/2<<endl<<
    a+b+sqrt(a*a+b*b-2*a*b*cos(c*PI/180))<<endl<<
    b*sin(c*PI/180)<<endl;

    return 0;
}

