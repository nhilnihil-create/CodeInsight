#include<bits/stdc++.h>
#include<math.h>
using namespace std;

const double rasian = M_PI*60.0/180.0;
  
typedef struct
{
  double x;
  double y;
}K;

void print(K plot)
{
  printf("%lf %lf\n",plot.x,plot.y);
}

void KochCurve(int n, K p1, K p2)
{
  if(n == 0) return;
  K s,t,u;
  
  s.x = (2.0*p1.x+1.0*p2.x)/3.0;
  s.y = (2.0*p1.y+1.0*p2.y)/3.0;

  t.x = (1.0*p1.x+2.0*p2.x)/3.0;
  t.y = (1.0*p1.y+2.0*p2.y)/3.0;

  u.x = (t.x-s.x)*cos(rasian)-(t.y-s.y)*sin(rasian)+s.x;
  u.y = (t.x-s.x)*sin(rasian)+(t.y-s.y)*cos(rasian)+s.y;
  
  KochCurve(n-1, p1, s);
  print(s);
  KochCurve(n-1, s, u);
  print(u);
  KochCurve(n-1, u, t);
  print(t);
  KochCurve(n-1, t, p2);
}

int main()
{
  int n;
  cin >> n;

  K plot1={0,0};
  K plot2={100,0};

  print(plot1);
  KochCurve(n,plot1,plot2);
  print(plot2);
  
  return 0;
}
