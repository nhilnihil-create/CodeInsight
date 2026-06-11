#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double pi=3.14159265359;

int main(){
  double a,b,x;
  cin >> a >> b >> x;
  if(x<a*b*a/2){
    double y=(a*b*b)/(2*x);
    cout << fixed << setprecision(10);
    cout << atan(y)*(double)180/pi << endl;
  }
  else{
    double y=2*(a*a*b-x)/(a*a*a);
    cout << fixed << setprecision(10);
    cout << atan(y)*(double)180/pi << endl;
  }
}