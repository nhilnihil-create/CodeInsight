#include<bits/stdc++.h>
using namespace std;

int main(){
double siita,a,b,c;
cin>>a>>b>>c;
siita=c/360*2*acos(-1);
printf("%.8lf\n%.8lf\n%.8lf\n",a*b*sin(siita)*0.5,a+b+sqrt(a*a+b*b-2*a*b*cos(siita)),a*b*sin(siita)/a);
return 0;
}
