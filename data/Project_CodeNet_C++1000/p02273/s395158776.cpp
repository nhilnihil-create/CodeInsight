#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
struct P{double x,y;};

void k(int n,P a,P b){
  if(n==0)return;
  P s,t,u;
  double th=M_PI*60.0/180.0;
  s.x=(2.0*a.x+1.0*b.x)/3;
  s.y=(2.0*a.y+1.0*b.y)/3;
  t.x=(1.0*a.x+2.0*b.x)/3;
  t.y=(1.0*a.y+2.0*b.y)/3;
  u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
  u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
  k(n-1,a,s);
  printf("%.8f %.8f\n",s.x,s.y);
  k(n-1,s,u);
  printf("%.8f %.8f\n",u.x,u.y);
  k(n-1,u,t);
  printf("%.8f %.8f\n",t.x,t.y);
  k(n-1,t,b);
} 

int main(){
  int n;
  P a,b;
  a.x=0,a.y=0,b.x=100,b.y=0;
  cin>>n;
  printf("%.8f %.8f\n",a.x,a.y);
  k(n,a,b);
  printf("%.8f %.8f\n",b.x,b.y);
  return 0;
}