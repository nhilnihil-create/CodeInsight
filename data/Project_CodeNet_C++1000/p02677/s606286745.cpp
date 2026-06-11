#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
double a,b,h,m;
cin>>a>>b>>h>>m;
double A=0.5*(h*60+m);
double B=(m/60.0)*360;
double C=abs(B-A);
C=C*(3.14159265358979323846/180.0);
double ans;
ans=pow(a,2)+pow(b,2)-2*a*b*cos(C);
printf("%0.18f", sqrt(ans));
}
