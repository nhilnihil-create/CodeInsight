#include <bits/stdc++.h>
using namespace std;

int main(){

long double a,b,x;
  cin >> a >> b >> x;
  
  x/=a*a;
  double ans;
  
  if(x*2>=b) ans=(180/M_PI)*atan(2*(b-x)/a);
  else{
x=2*a*x/b;
ans=(180/M_PI)*atan(b/x);
  }
  
  cout << fixed << setprecision(9) << ans << endl;
}