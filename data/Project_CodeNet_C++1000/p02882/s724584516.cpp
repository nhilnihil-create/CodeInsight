#include <bits/stdc++.h>
using namespace std;

int main() {
  long double a,b,x;
  cin >> a >> b >> x;
  
  if(x >= a*a*b/2){
    cout << fixed << setprecision(10) << 180 * atan( (2*(a*a*b-x))/(a*a*a) ) / M_PI << endl;
  }else{
    cout << fixed << setprecision(10) << 180 * atan( (a*b*b) / (2*x) ) / M_PI << endl;
  }
  
  return(0);
}