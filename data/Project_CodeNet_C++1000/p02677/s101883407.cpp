#include<bits/stdc++.h>
#include<math.h>

#define pi acos(-1)
using namespace std;
int main(){
   double a,b,h,m,temp,ans=0.0;                                
   cin >> a >> b >> h >> m;
   temp = m*6;
   double angle = ((60*h)+m)*360/(60*12);
   double ang = (angle-temp);
   double p = ang*(pi/180);
   ans = (a*a)+(b*b)-(2*a*b*cos(p));
   cout << fixed << setprecision(20) << sqrt(ans) << endl;
   return 0;
}