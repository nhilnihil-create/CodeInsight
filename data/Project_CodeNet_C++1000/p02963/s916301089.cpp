#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL INF=1e9;

LL s;

void into(){
  scanf("%lld",&s);
}

LL x[2],y[2];

void Get_ans(){
  x[0]=min((LL)(sqrt(s)+0.5),INF);
  y[1]=min(s/x[0]+1,INF);
  x[1]=1;
  y[0]=x[0]*y[1]-s;
}

void work(){
  Get_ans();
}

void outo(){
  printf("%lld %lld %lld %lld %lld %lld\n",x[0],y[0],x[1],y[1],0,0);
}

int main(){
  into();
  work();
  outo();
  return 0;
}