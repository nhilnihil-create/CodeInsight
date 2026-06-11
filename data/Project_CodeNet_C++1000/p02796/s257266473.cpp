#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,INF=(1<<30)-1;

int n;
struct seg{
  int l,r;
}a[N+9];

bool cmp(const seg &a,const seg &b){return a.r<b.r||a.r==b.r&&a.l<b.l;}

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	int x,l;
	scanf("%d%d",&x,&l);
	a[i].l=x-l;a[i].r=x+l;
  }
}

int ans;

void Get_ans(){
  sort(a+1,a+n+1,cmp);
  int now=-INF;
  for (int i=1;i<=n;++i)
	if (now<=a[i].l) now=a[i].r,++ans;
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