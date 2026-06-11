#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,mod=998244353;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int n,a[N+9],cnt[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
    scanf("%d",&a[i]);
	++cnt[a[i]];
  }
}

int ans;

void Get_ans(){
  if (a[0]) return;
  ans=1;
  for (int i=2;i<=n;++i) smul(ans,a[i]?cnt[a[i]-1]:0);
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