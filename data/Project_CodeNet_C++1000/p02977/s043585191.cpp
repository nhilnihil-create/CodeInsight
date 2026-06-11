#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,k,a[N];
int main(){
	n=read();
	k=1;
	while((k<<1)<=n)k<<=1;
	if(k==n)return !printf("No\n");
	if((k<<1)==n+1)k<<=1;
	printf("Yes\n");
	for(int i=1;i<=k;++i){
		a[i]=i;
	}
	if(!(n&1)){
		int t=n^k^1;
		for(int i=t;i>2;--i){
			swap(a[i],a[i-1]);
		}
		printf("%d %d\n",n,k);
		printf("%d %d\n",2*n,a[2]);
	}
	for(int i=1;i<k-1;++i){
		printf("%d %d\n",a[i],a[i+1]);
		printf("%d %d\n",a[i]+n,a[i+1]+n);
	}
	printf("%d %d\n",a[1],a[k-1]+n);
	for(int i=k;i<n;i+=2){
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i,1);
		printf("%d %d\n",i+1+n,1);
		printf("%d %d\n",i+n,i+1+n);
	}
	return 0;
}


