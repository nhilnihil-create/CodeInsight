#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000;

int n,a[N+9],ord[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	scanf("%d",&a[i]);
	ord[i]=a[i];
  }
}

int cnt[5],ans;

void Get_ans(){
  sort(ord+1,ord+n+1);
  int co=unique(ord+1,ord+n+1)-ord-1;
  if (co>3) return;
  for (int i=1;i<=n;++i) ++cnt[a[i]=lower_bound(ord+1,ord+co+1,a[i])-ord];
  if (co==1) {ans=ord[1]==0;return;}
  if (co==2) {ans=ord[1]==0&&cnt[2]==cnt[1]<<1;return;}
  if (co==3) {ans=(ord[1]^ord[2])==ord[3]&&cnt[1]==cnt[2]&&cnt[2]==cnt[3];return;}
}

void work(){
  Get_ans();
}

void outo(){
  puts(ans?"Yes":"No");
}

int main(){
  into();
  work();
  outo();
  return 0;
}