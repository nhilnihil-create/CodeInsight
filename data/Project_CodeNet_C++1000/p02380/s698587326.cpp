#include <bits/stdc++.h>
using namespace std;
int main(){
double a,b,c,h;
cin>>a>>b>>c;
h=b*sin(M_PI*c/180);
printf("%f\n%f\n%f\n",a*h/2,a+b+sqrt(( a-(b*cos(M_PI*c/180)) )*( a-(b*cos(M_PI*c/180)) )+h*h),h);
return 0;
}