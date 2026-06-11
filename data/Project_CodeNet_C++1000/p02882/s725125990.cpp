#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
#define se cout << fixed << setprecision(11)

int main(){
  double a,b,x;
  cin >> a >> b >> x;
  double c=x/a;
  
  double y;
  if(c>a*b/2){
    y=(2*x/(a*a))-b;
    double d=atan((b-y)/a);
    se << d*180/PI <<endl;
  }
  else{
    y=2*x/(b*a);
    double e=atan(b/y);
    se << e*180/PI <<endl;
  }
}

    