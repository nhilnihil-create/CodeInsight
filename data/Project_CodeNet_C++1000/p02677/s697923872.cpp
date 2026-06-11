#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;
int main()
{
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    double x,y,z,v;
    x=0.5*((60*h)+m);
    y=6*m;
    z=abs(x-y);
    v = z * PI / 180.0;
    double ans = a * a + b * b - 2 * a * b * cos(v);
    cout << setprecision(14)<<sqrt(ans)<<endl;
}