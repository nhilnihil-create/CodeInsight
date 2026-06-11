#include<bits/stdc++.h>

using namespace std;

int main(){
  
  cout << fixed << setprecision(12);
  
  double a,b,C;

  cin >> a >> b >> C;

  double PI = acos(-1.0);

  C = C / 180 * PI;

  cout << a * b * sin(C) / 2 << endl;
  cout << a + b + sqrt(a*a+b*b-2*a*b*cos(C)) << endl;
  cout << b * sin(C) << endl;

  return 0;
}
  
