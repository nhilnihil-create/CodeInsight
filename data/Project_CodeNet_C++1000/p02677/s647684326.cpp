#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
int main()
{
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    double h_angle = 0.5*(h*60+m);
    double m_angle = 6*m;
    double diff = abs(h_angle-m_angle);
    diff = diff*(M_PI/180.0);
    double sol = a*a+b*b-2*a*b*cos(diff);
    double ans = sqrt(sol);
    cout<<setprecision(10)<<ans;
}
