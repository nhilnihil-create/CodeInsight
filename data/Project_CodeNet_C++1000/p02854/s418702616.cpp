#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;
const LL INF=(1LL<<60)-1;

int n;
LL a[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	scanf("%lld",&a[i]);
	a[i]+=a[i-1];
  }
}

LL ans;

void Get_ans(){
  ans=INF;
  for (int i=1;i<n;++i){
	LL x=a[i],y=a[n]-a[i];
	ans=min(ans,abs(x-y));
  }
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