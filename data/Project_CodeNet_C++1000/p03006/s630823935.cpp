#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=50;

int n;
struct point{
  int x,y;
}a[N+9];

bool cmp(const point &a,const point &b){return a.x<b.x||a.x==b.x&&a.y<b.y;}

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d%d",&a[i].x,&a[i].y);
}

int Get_ans(int dx,int dy){
  int res=n;
  for (int i=1;i<=n;++i)
	for (int j=i+1;j<=n;++j)
	  if (a[j].x-a[i].x==dx&&a[j].y-a[i].y==dy) --res;
  return res;
}

int ans;

void Get_ans(){
  ans=n;
  sort(a+1,a+n+1,cmp);
  for (int i=1;i<=n;++i)
	for (int j=i+1;j<=n;++j) ans=min(ans,Get_ans(a[j].x-a[i].x,a[j].y-a[i].y));
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