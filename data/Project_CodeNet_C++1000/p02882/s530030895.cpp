#include <bits/stdc++.h>
using namespace std;

int main() {
  const double pi=3.141592653589;
  double a,b,x;
  cin >> a >> b >> x;
  double ans=0,k=0;
  if(x/a<a*b/2){
    k=(2*x)/(a*b);
    ans=atan(b/k)*180/pi; 
  }
  else if(x/a==a*b/2){
    ans=atan(b/a)*180/pi; 
  }
  else {
    k=((2*x)/(a*a))-b;
    ans=atan((b-k)/a)*180/pi;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
