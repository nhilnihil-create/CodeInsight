#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double a,b,x;
  cin >> a >> b >> x;
  if (a*a*b <= 2*x){
    double s = (a*a*b - x) / a;
    double t = 2*s / (a*a);
  
    //cout << s << " " << t << endl;
    cout << fixed << setprecision(10);
    cout << atan(t) * 57.2957795130 << endl;
  }
  else{
    double s = x / a;
    double t = b*b / (2*s);
    
    //cout << s << " " << t << endl;
    cout << fixed << setprecision(10);
    cout << atan(t) * 57.2957795130 << endl;
  }
}