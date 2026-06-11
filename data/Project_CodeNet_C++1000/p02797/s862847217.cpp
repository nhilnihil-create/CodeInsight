#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mx=1e9;
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
int n,k,s;
int main(){
	n=read(),k=read(),s=read();
	for(int i=1;i<=k;++i){
		printf("%d ",s);
	}
	for(int i=k+1;i<=n;++i){
		printf("%d ",s==mx?mx-1:s+1);
	}
	printf("\n");
	return 0;
}

