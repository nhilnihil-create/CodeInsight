#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
 
int main(){
 int a,b,C;
 double pi=acos(-1);
 cin >> a >> b >> C;
 
 double S=0.5*a*b*sin(C*pi/180);
 double c=sqrt((a*a+b*b)-2*a*b*cos(C*pi/180));
 double L=a+b+c;
 double h=2*S/a;
 
 cout << fixed << setprecision(8);
 cout << S << endl << L << endl << h << endl;
 return 0;
}