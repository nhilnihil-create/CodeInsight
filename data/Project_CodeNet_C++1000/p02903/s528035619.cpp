#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int n,m,A,B;
int main(){
	n=read(),m=read(),A=read(),B=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			putchar(((i>B)^(j>A))+'0');
		}
		putchar('\n');
	}
	return 0;
}

