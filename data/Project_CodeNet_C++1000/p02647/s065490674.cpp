#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],b[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int T=1;T<=m;++T){
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;++i){
			b[max(1,i-a[i])]++,b[min(n+1,i+a[i]+1)]--;
		}
		bool ok=true;
		for(int i=1;i<=n;++i){
			b[i]+=b[i-1];
			if(b[i]<n)ok=false;
		}
		swap(a,b);
		if(ok)break;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	return 0;
}
