#include<bits/stdc++.h>
#define ll long long 
#define inf 0x7fffffff
#define clr(c) memset(c,0,sizeof(c))
using namespace std;
int mod=998244353;
const int M=1e6+10;
const int N=2e5+10;
inline ll read(){
    ll b=1,sum=0; char c=getchar();
    while(!isdigit(c)){if(c=='-') b=-1; c=getchar();}
    while(isdigit(c)){sum=sum*10+c-'0'; c=getchar();}
    return b*sum;
}
int n,m,k,T;
int len,ans;
char s[M]; 
int a[M],vis[3]; 
int C(int y,int x) {
	if(x>y) return 0;
	return 1;
}
int lucas(int y,int x) {
	if(x==0) return 1;
	return C(y%mod,x%mod)*lucas(y/mod,x/mod);
}
int main() 
{
    int i,j;
    n=read();
	scanf("%s",s+1);
	mod=2;
	bool f=0;
	for(i=1;i<=n-1;i++) {
		a[i]=abs(s[i+1]-s[i]);
		if(a[i]==1) f=1;
	}
	if(f==0) {
		for(i=1;i<=n;i++) a[i]/=2;
	}
	for(i=1;i<=n-1;i++) {
		ans+=lucas(n-2,i-1)*a[i];
		ans%=2;
	}


	if(f==0) ans*=2;
	printf("%d",ans);
    return 0;
}
