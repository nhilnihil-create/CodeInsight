#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=2000,mod=1000000007;

int n,m,a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int c[N+9];

void Add(int p,int v){for (;p<=N;p+=p&-p) c[p]+=v;}
int Query(int p){int res=0;for (;p;p-=p&-p) res+=c[p];return res;}
int Query(int l,int r){return Query(r)-Query(l-1);}

int ans;

void Get_ans(){
  for (int i=1;i<=n;++i){
	ans+=Query(a[i]+1,N);
	Add(a[i],1);
  }
  ans=(LL)ans*m%mod;
  for (int i=1;i<=N;++i) c[i]=0;
  for (int i=1;i<=n;++i) ++c[a[i]];
  for (int i=N;i>=1;--i){
	ans=(((LL)m*(m-1)>>1)%mod*c[i]%mod*c[i+1]+ans)%mod;
	c[i]+=c[i+1];
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