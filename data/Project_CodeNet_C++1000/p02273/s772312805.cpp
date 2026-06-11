#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define N 8
using namespace std;

struct point{
  double x,y;
};

void koch(int d, point p1, point p2){
  point s,u,t;
  if (d==0) return;

  s.x=(2.0*p1.x+p2.x)/3;
  s.y=(2.0*p1.y+p2.y)/3;
  t.x=(p1.x+2.0*p2.x)/3;
  t.y=(p1.y+2.0*p2.y)/3;
  u.x=(t.x-s.x)*cos(M_PI/3)-(t.y-s.y)*sin(M_PI/3)+s.x;
  u.y=(t.x-s.x)*sin(M_PI/3)+(t.y-s.y)*cos(M_PI/3)+s.y;
  
  koch(d-1, p1, s);
  cout << fixed << setprecision(N) << s.x << " " << s.y << endl;
  koch(d-1, s, u);
  cout << fixed << setprecision(N) << u.x << " " << u.y << endl;
  koch(d-1, u, t);
  cout << fixed << setprecision(N) << t.x << " " << t.y << endl;
  koch(d-1, t, p2);
}

int main(){
  int n;
  cin >> n;
  point p1,p2;
  p1.x=p1.y=0;
  p2.x=100.0;
  p2.y=0;
  cout << fixed <<setprecision(N) << p1.x << " " << p1.y << endl;
  koch(n,p1,p2);
  cout << fixed <<setprecision(N) << p2.x << " " << p2.y << endl;
  return 0;
}

