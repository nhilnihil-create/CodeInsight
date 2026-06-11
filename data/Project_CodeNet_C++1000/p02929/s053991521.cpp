#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
#define N 200010
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
int n,a[N],ans; //0: 左端点；1：右端点 
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	int rem=0;
	for(int i=1;i<=(n<<1);++i){
		a[i]=(s[i]=='W')^(rem&1);
		rem+=(a[i]?-1:1); 
		if(rem<0)return !printf("0\n");
	}
	if(rem)return !printf("0\n");
	ans=1;
	for(int i=1;i<=(n<<1);++i){
		if(a[i]){
			ans=1LL*ans*rem%mod;
			--rem;
		}
		else{
			++rem;
		}
	}
	for(int i=1;i<=n;++i){
		ans=1LL*ans*i%mod;
	}
	printf("%d\n",ans);
	return 0;
}
