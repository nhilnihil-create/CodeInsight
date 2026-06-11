#include<bits/stdc++.h>
using namespace std;
double pi = acos(-1);
int main()
{
    double d,ans;
    double m,h,a,b;
    while(cin>>a>>b>>h>>m){

        h = (h*30) + ( m/2);
        m= m*6;
        ans = min( fabs(h-m), 360 - fabs(h-m));
        d= (ans*pi)/180;
        double c = (a*a) + ( b*b) - 2*a*b*cos(d);
        c= sqrt(c);
        cout<<setprecision(20)<<c<<endl;

    }

    return 0;
}
