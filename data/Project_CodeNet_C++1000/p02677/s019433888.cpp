#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  static const double pi = 3.141592653589793;
  
  int a,b,h,m;
  cin >> a >> b >> h >> m;
  
  double t,t1,t2;
  
  t1 = 30 * h + 0.5 * m;
  t2 = 6 * m;
  
  
  if(abs(t1-t2) > 180) t = 360 - (t1-t2);
  else t = (t1-t2);
  
  t /= 180; 
  
  double y = cos( M_PI * t );
  //cout << y << endl;
  
  double c = a*a + b*b - 2*a*b*y;
  
  c = sqrt(c); 
  
  cout << fixed << setprecision(20) << c;
}