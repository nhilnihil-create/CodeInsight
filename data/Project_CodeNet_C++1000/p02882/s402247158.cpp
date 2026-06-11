#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double ans;
  cout << fixed << setprecision(10);
  double pi = 3.141592653589793238;
  double unit = 180.0 / pi;
  if(x < a*a*b/2){
    double p = x*2/(a*b);
    cout << atan(b/p)*unit << endl;
  }
  else{
    double p = (a*a*b-x)*2/(a*a);
    cout << atan(p/a)*unit << endl;
  }
}
    