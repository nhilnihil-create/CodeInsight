#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,INF=(1<<30)-1;

int n,m,sk,a[N+9],b[N+9];

int main(){
  scanf("%d%d%d",&n,&m,&sk);
  int mn0=INF,mn1=INF;
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	mn0=min(mn0,a[i]);
  }
  for (int i=1;i<=m;++i){
	scanf("%d",&b[i]);
	mn1=min(mn1,b[i]);
  }
  int ans=mn0+mn1;
  for (int i=1;i<=sk;++i){
	int x,y,c;
	scanf("%d%d%d",&x,&y,&c);
	ans=min(ans,a[x]+b[y]-c);
  }
  printf("%d\n",ans);
  return 0;
}