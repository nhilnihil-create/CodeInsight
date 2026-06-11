#include<bits/stdc++.h>
using namespace std;
int main(){
double pi=3.14159265358979323846264338327950;
  double a,b,h,m;
  cin >> a >> b >> h >> m;
  long double deg;
  deg = 2*pi*((h/12+m/60/12) - (m/60));
  long double ans;
  ans = (a*a+b*b) - (2*a*b*cosl(deg));
  cout << setprecision(15) << sqrtl(ans) << endl;
}