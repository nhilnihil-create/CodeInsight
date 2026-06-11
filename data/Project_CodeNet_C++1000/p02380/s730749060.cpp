#include<bits/stdc++.h>
using namespace std;

int main(){

cout<<fixed<<setprecision(12);
double a,b,C,h;
cin>>a>>b>>C;
C=C*acos(-1)/180;
h=b*sin(C);
double c=sqrt(a*a+b*b-2*a*b*cos(C));

cout<<a*h/2<<endl<<a+b+c<<endl<<h<<endl;


return 0;
}
