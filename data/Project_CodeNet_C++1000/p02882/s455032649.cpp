#include <bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
int main()
{
    double a,b,x,ans;
    cin>>a>>b>>x;
    double s=x/a;
    if(s*2.0<=a*b)
    {
        double aa=s*2.0/b;
        ans=90.0-atan(aa/b)*180.0/PI;
    }
    else
	{
        double x=(s*2.0-a*b)/a;
        ans=90.0-atan(a/(b-x))*180.0/PI;
    }
    cout<<fixed<<setprecision(10)<<ans;
}