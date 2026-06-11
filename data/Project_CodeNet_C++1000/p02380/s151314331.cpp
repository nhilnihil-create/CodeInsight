#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
double a,b,c;
double S,L,h;
cin>>a>>b>>c;
S=1/2.0*a*b*sin(c/180.0f*M_PI);
L=a+b+sqrt(a*a+b*b-2.0*a*b*cos(c/360.0*2.0*M_PI));
h=2.0*S/a;
cout<<fixed << setprecision(10)<<S<<endl;
cout<<fixed << setprecision(10)<<L<<endl;
cout<<fixed << setprecision(10)<<h<<endl;
}