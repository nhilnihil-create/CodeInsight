#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
static const double PI=acos(-1.0);

int main(){
    double a,b,x;
    cin>>a>>b>>x;

    x/=a;
    double ans;
    if(x>a*b/2) ans=atan(2*(a*b-x)/(a*a));
    else ans=atan(b*b/(2*x));
    ans=ans*180/PI;
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
}