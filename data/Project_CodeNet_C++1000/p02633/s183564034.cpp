#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int x;
int main(){
	x=read();
	printf("%d\n",360/__gcd(360,x));
	return 0;
}

