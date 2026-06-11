#include<cstdio>
#include<cmath>

struct Point{
  double x;
  double y;
  
  void print(){
    std::printf("%f %f\n",x,y);
  }
};

void koch(int n,Point p1,Point p2){
  Point s,t,u;
  
  if(n == 0) return;
  
  s.x = (2 * p1.x + p2.x) / 3.0;
  s.y = (2 * p1.y + p2.y) / 3.0;
  t.x = (p1.x + 2 * p2.x) / 3.0;
  t.y = (p1.y + 2 * p2.y) / 3.0;
  
  u.x = (t.x - s.x) * cos(60.0 * M_PI / 180.0)
    - (t.y - s.y) * sin(60.0 * M_PI / 180.0) + s.x;
  
  u.y = (t.x - s.x) * sin(60.0 * M_PI / 180.0)
    + (t.y - s.y) * cos(60.0 * M_PI / 180.0) + s.y;
  
  koch(n - 1,p1,s);
  s.print();
  koch(n - 1,s,u);
  u.print();
  koch(n - 1,u,t);
  t.print();
  koch(n - 1,t,p2);
}

int main(){
  int n;
  Point p1,p2;
  
  std::scanf("%d",&n);
  
  p1.x = 0.0;
  p1.y = 0.0;
  p2.x = 100.0;
  p2.y = 0.0;
  
  p1.print();
  koch(n,p1,p2);
  p2.print();
  
  return 0;
}
