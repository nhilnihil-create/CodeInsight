//itp1_10b
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
 int a,b,c;
 double s,l,h,cl;
 double rad=M_PI/180;

 cin>>a>>b>>c;
 cl=sqrt(a*a+b*b-2.0*a*b*cos(c*rad));
 h=b*sin(c*rad);
 l=a+b+cl;
 s=a*h/2.0;
 printf("%.8f\n",s);
 printf("%.8f\n",l);
 printf("%.8f\n",h);

 return 0;
}