#include<iostream>
#include<cstdio>

using namespace std;

#define maxn 1000010
int notp[maxn];
int vis[maxn];
int prm[maxn],tot;
int ai[maxn];

int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}

void sieve(int n){
	notp[1]=1;
	for(int i=2;i<=n;i++){
		if(!notp[i])
			prm[++tot]=i;
		for(int j=1;1ll*prm[j]*i<=n&&j<=tot;j++){
			notp[i*prm[j]]=1;
			if(i%prm[j]==0)
				break;
		}
	}
}

inline int readin(){
	int x=0,s=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*s;
}

int main(){
	int n,g;
	n=readin();
	sieve(1000001);
	for(int i=1;i<=n;i++)
		ai[i]=readin();
	g=ai[1];
	for(int i=2;i<=n;i++)
		g=gcd(g,ai[i]);
	if(g>1){
		puts("not coprime");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!notp[ai[i]])vis[ai[i]]++;
		else {
			for(int j=1;j<=100&&prm[j]<=ai[i];j++){
				if(ai[i]%prm[j]==0){
					vis[prm[j]]++;
				}
				while(ai[i]%prm[j]==0)
					ai[i]/=prm[j];
			}
			if(ai[i]>1)vis[ai[i]]++;
		}
	}
	for(int i=2;i<=1000000;i++)
		if(vis[i]>=2){
			puts("setwise coprime");
			return 0;
		}
	puts("pairwise coprime");
        return 0+0-0+0;
}