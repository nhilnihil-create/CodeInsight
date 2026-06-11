#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


struct xy{
  double  x,y;
};

void koch(int n,xy p1,xy p2){
  if(n==0)return ;
xy s,t,u;
  s.x=(2*p1.x+p2.x)/3;
  s.y=(2*p1.y+p2.y)/3;
  t.x=(p1.x+2*p2.x)/3;
  t.y=(p1.y+2*p2.y)/3;
  u.x=(t.x-s.x)/2-(t.y-s.y)*(sqrt(3.0)/2)+s.x;
  u.y=(t.x-s.x)*(sqrt(3.0)/2)+(t.y-s.y)/2+s.y;

  koch(n-1,p1,s);
  printf("%f %f\n",s.x,s.y);
  koch(n-1,s,u);
  printf("%f %f\n",u.x,u.y);
  koch(n-1,u,t);
  printf("%f %f\n",t.x,t.y);
  koch(n-1,t,p2);
}


int main(){
  int n;
  cin>>n;
  xy p1,p2;
  p1.x=0,p1.y=0;
  p2.x=100,p2.y=0;
  printf("%f %f\n",p1.x,p1.y);
  koch(n,p1,p2);
  printf("%f %f\n",p2.x,p2.y);
  return 0;
}