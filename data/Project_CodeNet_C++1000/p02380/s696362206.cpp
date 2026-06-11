#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    // Here your code !
 int a,b,C;
 double S,L,h,c;
double Pi=acos(-1); 
 cin>>a>>b>>C;
 c=sqrt((a*a+b*b)-2*a*b*cos(C*Pi/180));
 L=a+b+c;
 S=0.5*a*b*sin(C*Pi/180);
 h=2*S/a;
 
 cout<<fixed<<setprecision(8);
 cout<<S<<' '<<L<<' '<<h<<endl;
 
}