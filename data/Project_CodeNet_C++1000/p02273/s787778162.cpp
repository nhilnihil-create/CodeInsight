#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

typedef struct{
  double x,y;
}point;
  
void koch(point p1,point p2,int n,int i,int angle){
  point s,t,u;
  double r=sqrt(((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)))/3;

  if (n<i)return;
  //  cout << "dbg" << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << endl;

  s.x=(p2.x-p1.x)/3+p1.x;
  s.y=(p2.y-p1.y)/3+p1.y;
  t.x=(p2.x-p1.x)*2/3+p1.x;
  t.y=(p2.y-p1.y)*2/3+p1.y;
  //cout << "dbg" << r << " " << cos(i*M_PI/3) << endl;
  u.x=r*cos(angle*M_PI/3)+s.x;
  u.y=r*sin(angle*M_PI/3)+s.y;

  //  cout << p1.x << " " << p1.y << endl;
  koch(p1,s,n-1,i,angle);
  printf("%.8f %.8f\n",s.x,s.y);
  koch(s,u,n,i+1,angle+1);
  printf("%.8f %.8f\n",u.x,u.y);
  koch(u,t,n,i+1,angle-1);
  printf("%.8f %.8f\n",t.x,t.y);
  koch(t,p2,n-1,i,angle);
  //  cout << p2.x << " " << p2.y << endl; 
}

int main(){
  int n;
  point p1={0,0},p2={100,0};
  
  cin >> n;
  cout << p1.x << " " << p1.y << endl;
  koch(p1,p2,n,1,1);
  cout << p2.x << " " << p2.y << endl; 

  return 0;
}