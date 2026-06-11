#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int x,y;

void into(){
  scanf("%d%d",&x,&y);
}

void work(){
}

void outo(){
  printf("%d\n",(x<=3?(4-x)*100000:0)+(y<=3?(4-y)*100000:0)+(x==1&&y==1)*400000);
}

int main(){
  into();
  work();
  outo();
  return 0;
}