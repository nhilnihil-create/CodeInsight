#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500;

int n;

void into(){
  scanf("%d",&n);
}

int ans[N+9][N+9];

void Divide_ans(int l,int r,int d){
  if (l==r) return;
  int mid=l+r>>1;
  for (int i=l;i<=mid;++i)
	for (int j=mid+1;j<=r;++j) ans[i][j]=d;
  Divide_ans(l,mid,d+1);
  Divide_ans(mid+1,r,d+1);
}

void work(){
  Divide_ans(1,n,1);
}

void outo(){
  for (int i=1;i<n;++i){
	for (int j=i+1;j<=n;++j) printf("%d ",ans[i][j]);
	puts("");
  }
}

int main(){
  into();
  work();
  outo();
  return 0;
}