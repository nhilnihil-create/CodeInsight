#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926

typedef struct{

  double x,y;
}pxy_t;

void kock(int n,pxy_t p1 , pxy_t p2){

  if(n==0)return;

  pxy_t s,t,u;

  s.x = (2*p1.x + p2.x)/3.0;
  s.y = (2*p1.y + p2.y)/3.0;

  t.x = (p1.x + 2*p2.x)/3.0;
  t.y = (p1.y + 2*p2.y)/3.0;    

  u.x = (t.x-s.x)*cos(60.0/180*PI) - (t.y-s.y)*sin(60.0/180*PI) + s.x;
  u.y = (t.x-s.x)*sin(60.0/180*PI) + (t.y-s.y)*cos(60.0/180*PI) + s.y;

  kock(n-1,p1,s);
  printf("%.8f %.8f\n",s.x,s.y);
  kock(n-1,s,u);
  printf("%.8f %.8f\n",u.x,u.y);
  kock(n-1,u,t);
  printf("%.8f %.8f\n",t.x,t.y);
  kock(n-1,t,p2);

}


int main(){

  int n;

  cin >> n;

  pxy_t begin={0,0} , end={100,0};

  printf("%.8f %.8f\n",begin.x,begin.y);

  kock(n,begin,end);

  printf("%.8f %.8f\n",end.x,end.y);

  return 0;
}