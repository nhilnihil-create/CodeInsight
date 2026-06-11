#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,m;

void into(){
  scanf("%d%d",&n,&m);
}

int ans;

void Get_ans(){
  for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j){
	  int x=j/10,y=j%10;
	  ans+=x>=2&&y>=2&&x*y==i;
	  //if (x>=2&&y>=2&&x*y==i) printf("%d %d %d\n",i,x,y);
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