#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 200020
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
int n,a[N],b[N];
ll ans;
priority_queue<pair<int,int> > q;
#define las(x) (x==1?n:(x-1))
#define nxt(x) (x==n?1:(x+1))
#define NO !printf("-1\n")
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	} 
	for(int i=1;i<=n;++i){
		if(a[i]^b[i])q.push(make_pair(b[i],i));
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		int s=b[las(u)]+b[nxt(u)];
		if(s>=b[u])return NO; 
		if(s<=a[u]){
			if((b[u]-a[u])%s)return NO;
			ans+=(b[u]-a[u])/s;
		}
		else{
			ans+=b[u]/s;
			b[u]%=s;
			if(b[u]<a[u])return NO;
			else if(b[u]>a[u]){
				q.push(make_pair(b[u],u));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

