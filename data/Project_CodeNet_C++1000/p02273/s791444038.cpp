#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.14159265
using namespace std;

struct Point{
  double x;
  double y;
  Point(double _x,double _y){
    x=_x;
    y=_y;
  }
};

Point* rotate(Point p, Point base, double rad){
  return new Point(
      cos(rad)*(p.x-base.x) - sin(rad)*(p.y-base.y) + base.x,
      sin(rad)*(p.x-base.x) + cos(rad)*(p.y-base.y) + base.y);
}

void koch(Point p1,Point p2,int depth){
  if(depth==0){
    printf("%.8lf %.8lf\n",p1.x,p1.y);
    return;
  }
  Point *s,*t,*u;
  s = new Point( (p2.x - p1.x)/3.0 + p1.x, (p2.y - p1.y)/3.0 + p1.y );
  t = new Point( (p2.x - p1.x)*2.0/3.0 + p1.x, (p2.y - p1.y)*2.0/3.0  + p1.y);
  u = rotate(*t,*s,PI/3.0);
  koch(p1,*s,depth-1);
  koch(*s,*u,depth-1);
  koch(*u,*t,depth-1);
  koch(*t,p2,depth-1);
}

int main(){
  int n; cin>>n;
  Point p1(0,0);
  Point p2(100,0);
  koch(p1,p2,n);
  printf("%.8lf %.8lf\n",p2.x,p2.y);
}