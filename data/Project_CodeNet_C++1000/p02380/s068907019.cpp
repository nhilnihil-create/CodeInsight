#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int a, b;
    double c, s, l, h;
    cin>>a>>b>>c;
    double pi=acos(-1.0);
    c=c*pi/180.0;
    s=(a*b*sin(c))/2.0;
    l=a+b+sqrt(a*a+b*b-2.0*a*b*cos(c));
    h=2.0*s/a;
    cout<<fixed<<setprecision(4)<<s<<endl<<l<<endl<<h<<endl;
    return 0;
}

