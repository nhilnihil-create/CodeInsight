#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct po{double x, y;};

void saiki(po p1,po p2,int dep){
  if(dep==0) return;
  po s,t,u;
  s.x=(2*p1.x+p2.x)/3;
  s.y=(2*p1.y+p2.y)/3;
  t.x=(p1.x+2*p2.x)/3;
  t.y=(p1.y+2*p2.y)/3;
  u.x=(t.x-s.x)/2-(t.y-s.y)*(sqrt(3.0)/2)+s.x;
  u.y=(t.x-s.x)*(sqrt(3.0)/2)+(t.y-s.y)/2.0+s.y;

  saiki(p1,s,dep-1);
  printf("%.8f %.8f\n",s.x,s.y);
  saiki(s,u,dep-1);
  printf("%.8f %.8f\n",u.x,u.y);
  saiki(u,t,dep-1);
  printf("%.8f %.8f\n",t.x,t.y);
  saiki(t,p2,dep-1);
}

int main(){
  int n;
  cin>>n;
  po a,b;
  a.x=0,a.y=0;
  printf("%.8f %.8f\n",a.x,a.y);
  
  b.x=100,b.y=0;
  saiki(a,b,n);
  printf("%.8f %.8f\n",b.x,b.y);
  return 0;
}