#include<bits/stdc++.h>
using namespace std;
int n;

struct P{
  double x,y;
};

void dfs(P p1,P p2,int d){
  double px=(p2.x-p1.x)/3,py=(p2.y-p1.y)/3;
  P s,u,t,u2;
  if(d==n){
    printf("%.5f %.5f\n",p1.x,p1.y);
    return;
  }
  s.x=p1.x+px,s.y=p1.y+py;
  t.x=p1.x+2*px,t.y=p1.y+2*py;
  u2=t;
  u2.x-=s.x,u2.y-=s.y;
  u.x=u2.x/2-u2.y*sqrt(3)/2;
  u.y=u2.x*sqrt(3)/2+u2.y/2;
  u.x+=s.x,u.y+=s.y;
  dfs(p1,s,d+1);
  dfs(s,u,d+1);
  dfs(u,t,d+1);
  dfs(t,p2,d+1);
}

int main(){
  P a,b;
  a.x=0,a.y=0;
  b.x=100,b.y=0;
  cin>>n;
  dfs(a,b,0);
  printf("%.5f %.5f\n",b.x,b.y);
  return 0;
}