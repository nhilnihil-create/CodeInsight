#include <bits/stdc++.h>
using namespace std;

double a,b,x;

int main() {
  cin >> a >> b >> x;
  if (x/a > (a*b)/2) {
    double theta=atan((2*b)/a-(2*x)/(a*a*a));
    cout << setprecision(15) << theta*180/acos(-1.0) << endl;
  }
  else {
    double theta=atan((a*b*b)/(2*x));
    cout << setprecision(15) << theta*180/acos(-1.0) << endl;
  }
}