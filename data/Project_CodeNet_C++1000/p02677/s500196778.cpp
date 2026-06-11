#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double pi=acos(-1);
int main()
{
    double a,b,h,m,ma,ha,a1,a2,angle,l,d,s;
    cin>>a>>b>>h>>m;
    ma=m*(6.0);
    ha=h*(30.0);
    ha=ha+((0.5)*m);
    if(ma==0.0)
    {
        ma=360.0;
    }
    if(ha==0.0)
    {
        ha=360.0;
    }
    if(ha>=ma)
    {
        angle=ha-ma;
    }
    else
    {
        angle=ma-ha;
    }
    angle=(angle*pi)/180.0;
    l=(a*a)+(b*b)-((2*a*b)*cos(angle));
    d=sqrt(l);
    cout<<fixed<<showpoint<<setprecision(20)<<d<<endl;
    return 0;    
}