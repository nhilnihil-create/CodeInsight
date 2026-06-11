#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,m,v,p,a[N+9];

void into(){
  scanf("%d%d%d%d",&n,&m,&v,&p);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

LL sum[N+9];
int ans;

void Get_ans(){
  sort(a+1,a+n+1,greater<int>());
  for (int i=1;i<=n;++i){
	sum[i]=sum[i-1]+a[i];
	if (i<=p) {ans=i;continue;}
	LL t=max(v-p-n+i,0),now=(LL)(a[i]+m)*(i-p)-sum[i-1]+sum[p-1];
    if (a[p]<=a[i]+m&&t*m<=now) ans=i;
	else break;
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}