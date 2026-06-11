#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
int d[100],a[100010];
signed main(){
	n=read();
	int s=0;
	for(register int i=1;i<=n;i++){a[i]=read();s^=a[i];}
	int ans=s,max_=(1ll<<61)-1;
	for(register int i=1;i<=n;i++){
		a[i]=(a[i] & (~s));
	}
	for(register int i=1;i<=n;i++){
		for(register int j=60;j>=0;j--){
			if((a[i] & (1ll<<j))!=0){
				if(d[j]==0){d[j]=a[i];break;}
				else a[i]=a[i]^d[j];
			}
		}
	}
	int anss=0;
	for(register int i=60;i>=0;i--)
		if((anss^d[i])>anss)anss^=d[i];
	printf("%lld\n",anss*2+ans);
	return 0;
}