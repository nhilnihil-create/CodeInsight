#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;

int n,m,uni[N+9],ans;

int Query_uni(int k){return k==uni[k]?k:uni[k]=Query_uni(uni[k]);}

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i) uni[i]=i;
  ans=n-1;
  for (int i=1;i<=m;++i){
	int x,y;
	scanf("%d%d",&x,&y);
	x=Query_uni(x);y=Query_uni(y);
	if (x==y) continue;
	--ans;
	uni[x]=y;
  }
}

void work(){
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