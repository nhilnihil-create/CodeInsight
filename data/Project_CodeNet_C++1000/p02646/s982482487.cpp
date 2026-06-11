#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
int A,B,V,W,T;
int main(){
	A=read(),V=read();
	B=read(),W=read();
	T=read();
	if(1LL*(V-W)*T>=abs(A-B)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
