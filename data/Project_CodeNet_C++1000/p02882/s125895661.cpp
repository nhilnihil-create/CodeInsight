#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    double checker=(1.0*x)/(1.0*pow(a,2));
    if (checker<((1.0*b)/(2.0)))
    {
        double angle1=atan2(2*x,a*pow(b,2));
        angle1=angle1*180/3.141592653589793;
        cout<<fixed<<setprecision(10)<<(90.0-angle1)<<endl;
        return 0;
    }
    double val1=1.0*(a/2.0);
    double val2=1.0*(b-1.0*(x/(1.0*pow(a,2))));
    double angle=atan2(val1,val2);
    angle=angle*180/3.141592653589793;
    cout<<fixed<<setprecision(10)<<(90.0-angle)<<endl;
    return 0;
}