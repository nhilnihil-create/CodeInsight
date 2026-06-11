#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500000;

char s[N+9];
int n;

void into(){
  scanf("%s",s+1);
  n=strlen(s+1);
}

int a[N+9];
LL ans;

void Dfs_a0(int p,int v){
  a[p]=max(a[p],v);
  if (p>1&&s[p-1]=='>') Dfs_a0(p-1,v+1);
}

void Dfs_a1(int p,int v){
  a[p]=max(a[p],v);
  if (p<=n&&s[p]=='<') Dfs_a1(p+1,v+1);
}

void Get_ans(){
  for (int i=1;i<=n+1;++i) a[i]=-1;
  for (int i=1;i<=n+1;++i)
	if ((i==1||s[i-1]=='>')&&(i==n+1||s[i]=='<')){
	  a[i]=0;
	  Dfs_a0(i-1,1);
	  Dfs_a1(i+1,1);
	}
  for (int i=1;i<=n+1;++i) ans+=a[i];
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