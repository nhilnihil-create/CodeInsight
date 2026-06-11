#include <bits/stdc++.h>
using namespace std;
 
int main() {
long double a,b,h,m;
 cin>>a>>b>>h>>m;
 static const long double pi = 3.141592653589793238462643;
long double kaku=0.00000000000000;
long double rag=0.0000000000000;
long double ans;
 if (h*30+m/2>m*6)
 {
    kaku=h*30+m/2-m*6;
 }
 else
 {
      kaku=m*6-(h*30+m/2);
 }
if (kaku>180)
{
    kaku=360-kaku;
}
 
 
rag=kaku*pi/180.000000000000;
 ans=sqrt(a*a+b*b-2*a*b*cos(rag));
 cout<< std::setprecision(20)<<ans<<endl;
 
 
 
}