#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){

double a,b,c;
double s,l,h;

cin>>a>>b>>c;
c=M_PI/180*c;
s=0.5*a*b*sin(c);
l=a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c));
h=b*sin(c);

cout<<fixed<<s<<endl<<l<<endl<<h<<endl;
}
