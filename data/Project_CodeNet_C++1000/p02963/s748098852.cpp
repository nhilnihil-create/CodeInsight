#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int p=1e9;
inline ll read(){
	ll x=0,f=1;
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
ll S,X1,Y1,X2,Y2;
int main(){
	S=read();
	X1=p,Y2=(S-1)/p+1,X2=1,Y1=X1*Y2-S;
	printf("0 0 %lld %lld %lld %lld\n",X1,Y1,X2,Y2);
	return 0;
}

