#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double pi = 3.141592653589793; 
  double x=sqrt(a*a+b*b-2*a*b*cos(2*pi*((h*60+m)/720-m/60)));
  cout << fixed << setprecision(15) << x << endl;
}