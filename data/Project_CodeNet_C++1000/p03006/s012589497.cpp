#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 55
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
int n,x[N],y[N],ans;
int Solve(int p,int q){
	int tot=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(x[i]+p==x[j]&&y[i]+q==y[j]){
				--tot;
				break;
			}
		}
	}
	return tot;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
	}
	ans=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			ans=min(ans,Solve(x[i]-x[j],y[i]-y[j]));
		}
	}
	printf("%d\n",ans);
	return 0;
}

