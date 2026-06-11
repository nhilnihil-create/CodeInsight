#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,INF=1000000000;

int n,m,sum;

void into(){
  scanf("%d%d%d",&n,&m,&sum);
}

int ans[N+9];

void Get_ans(){
  for (int i=1;i<=n;++i) ans[i]=i<=m?sum:sum==INF?1:sum+1;
}

void work(){
  Get_ans();
}

void outo(){
  for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
  puts("");
}

int main(){
  into();
  work();
  outo();
  return 0;
}