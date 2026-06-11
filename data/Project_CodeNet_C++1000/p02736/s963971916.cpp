#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int n,a[N],ans;
char s[N];
bool type;
int C(int n,int m){
	if(n==m||!m)return 1;
	if(n<m)return 0;
	return C(n&1,m&1)*C(n>>1,m>>1);
}
int main(){
	n=read();
	scanf("%s",s+1);
	type=false;
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'1';
		type|=a[i]&1;
	}
	if(!type){
		for(int i=1;i<=n;++i){
			a[i]>>=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]&1)ans^=C(n-1,i-1);
	}
	if(!type)ans<<=1;
	printf("%d\n",ans);
	return 0;
}

