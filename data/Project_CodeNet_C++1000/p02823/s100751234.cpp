#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
ll n,A,B;
int main(){
	n=read(),A=read(),B=read();
	if((B-A)&1){
		printf("%lld\n",min((A+B-1)>>1,(n-A+n-B+1)>>1));
	}
	else{
		printf("%lld\n",(B-A)>>1);
	}
	return 0;
}
