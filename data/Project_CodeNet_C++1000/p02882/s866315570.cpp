#include <bits/stdc++.h>
using namespace std;

double a, b, x;

bool f(double m){
  if(x*2 <= a*a*b)
    return x*tan(m)*2/a <= b*b;
  else
    return tan(m)*a/2 <= b-x/a/a*1.0;
}

int main(){
  cin >> a >> b >> x;

  double s = 0, t = 90, pi = 3.141592653589793;
  for(int i=0; i<100; i++){
    double mid = (s + t) / 2;
    if(f(mid*pi/180))  s = mid;
    else  t = mid;
  }

  printf("%.10lf\n", s);

  return 0;
}
