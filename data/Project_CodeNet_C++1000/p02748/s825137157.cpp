#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
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
int A,B,m,a[N],b[N],ans;
int main(){
	A=read(),B=read(),m=read();
	for(int i=1;i<=A;++i){
		a[i]=read();
	}
	for(int i=1;i<=B;++i){
		b[i]=read();
	}
	ans=(*min_element(a+1,a+A+1))+(*min_element(b+1,b+B+1));
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		ans=min(ans,a[x]+b[y]-read());
	}
	printf("%d\n",ans);
	return 0;
}

