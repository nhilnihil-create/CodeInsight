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
int H1,H2,M1,M2,k;
int main(){
	H1=read(),M1=read(),H2=read(),M2=read(),k=read();
	int p=(H2-H1)*60+(M2-M1);
	printf("%d\n",max(0,p-k));
	return 0;
}

