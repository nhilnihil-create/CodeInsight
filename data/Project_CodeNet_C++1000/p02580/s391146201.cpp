#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back 
#define fir first
#define sec second
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=300005;
int n,m,w;
int row[N],col[N],X[N],Y[N];
int main(){
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=w;i++){
		X[i]=read(),Y[i]=read();
		row[X[i]]++,col[Y[i]]++;
	}
	int maxr=0,maxc=0,mr=0,mc=0;
	for(int i=1;i<=n;i++){
		if(row[i]>maxr)maxr=row[i],mr=1;
		else if(row[i]==maxr)mr++;
	}
	for(int i=1;i<=m;i++){
		if(col[i]>maxc)maxc=col[i],mc=1;
		else if(col[i]==maxc)mc++;
	}
	int ret=0;
	for(int i=1;i<=w;i++){
		if(row[X[i]]==maxr&&col[Y[i]]==maxc)ret++;
	}	
	if(ret==1ll*mr*mc)printf("%d\n",maxr+maxc-1);
	else printf("%d\n",maxr+maxc);
	return 0;
}