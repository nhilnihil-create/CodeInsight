#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n,m,sk;

void into(){
  scanf("%d%d%d",&n,&m,&sk);
}

int ans;

void Get_ans(){
  if (n>m) swap(n,m);
  for (int i=0;i<=n;++i)
	if (i*m>=sk) {ans=i;return;}
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