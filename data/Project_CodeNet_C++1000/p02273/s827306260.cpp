#include <bits/stdc++.h>
using namespace std;

struct xy{
  double x, y;
};

void koch(int n, xy a, xy b){

  if(n == 0) return;

  xy s, t, u;
  double v = M_PI * 60.0/180.0;

  s.x = (a.x*2 + b.x)/3;
  s.y = (a.y*2 + b.y)/3;
  t.x = (a.x + b.x*2)/3;
  t.y = (a.y + (b.y*2))/3;
  u.x = (t.x - s.x)*cos(v) - (t.y - s.y)*sin(v) + s.x;
  u.y = (t.x - s.x)*sin(v) + (t.y - s.y)*cos(v) + s.y;


  koch(n-1,a,s);
  printf("%.8f %.8f\n",s.x,s.y);
  koch(n-1,s,u);
  printf("%.8f %.8f\n",u.x,u.y);
  koch(n-1,u,t);
  printf("%.8f %.8f\n",t.x,t.y);
  koch(n-1,t,b);




}

int main(){

  int n;
  cin >> n;

  xy a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  printf("%.8f %.8f\n",a.x,a.y);
  koch(n,a,b);
  printf("%.8f %.8f\n",b.x,b.y);



}