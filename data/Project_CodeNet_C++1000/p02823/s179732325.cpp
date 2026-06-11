#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n,a,b;

void into(){
  scanf("%lld%lld%lld",&n,&a,&b);
}

LL ans;

void Get_ans(){
  if (a>b) swap(a,b);
  if (b-a&1^1) {ans=b-a>>1;return;}
  ans=min(a,n-b+1)+(b-a-1>>1);
}

void work(){
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}