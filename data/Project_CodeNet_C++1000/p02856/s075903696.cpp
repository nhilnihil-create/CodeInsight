#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n;
LL cnt,sum;

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	LL d,c;
	scanf("%lld%lld",&d,&c);
	cnt+=c;sum+=d*c;
  }
}

void work(){
}

void outo(){
  printf("%lld\n",cnt-1+(sum-1)/9);
}

int main(){
  into();
  work();
  outo();
  return 0;
}