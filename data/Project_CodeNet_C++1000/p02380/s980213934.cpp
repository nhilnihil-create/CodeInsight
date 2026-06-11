#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(void){
    cout<<fixed<<setprecision(12);
    
    double a,b,C,rC,S,L;
    
    cin>>a>>b>>C;
    rC=C*M_PI/180;
    
    S=(a*b*sin(rC))/2;
    L=a+b+sqrt(a*a+b*b-2*a*b*cos(rC));
    
    cout<<S<<endl;
    cout<<L<<endl;
    cout<<2*S/a<<endl;
    
}

