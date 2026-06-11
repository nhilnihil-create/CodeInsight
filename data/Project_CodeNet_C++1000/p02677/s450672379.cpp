#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

    const double pi=3.141592653589793;
    double A,B,H,M,h,m;
    cin>>A>>B>>H>>M;
    double powA=A*A,powB=B*B;

    h=pi/6.0*H+pi/360.0*M;
    m=pi/30*M;
    double t=abs(h-m);
    double ans=sqrt(powA+powB-2*A*B*cos(t));
    
    cout<<fixed<<setprecision(15)<<ans<<endl;

    return 0;
}