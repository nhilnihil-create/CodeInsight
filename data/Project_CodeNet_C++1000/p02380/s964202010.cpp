#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    
    double a, b, c;
    double s, l, h;
    cin>>a>>b>>c;
    c=c*M_PI/180;
    s = a*b*sin(c)/2;
    l = a+b+sqrt(a*a+b*b-2*a*b*cos(c));
    h = s*2/a;
    cout<<s<<'\n'<<l<<'\n'<<h<<'\n';
    return 0;
}