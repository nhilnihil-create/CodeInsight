#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
int c[maxn];
inline int R_Int(){
	int ch,a;
	while(ch=getchar(),ch<'0'||ch>'9');a=ch^48;
	while(ch=getchar(),ch>='0'&&ch<='9')a=a*10+(ch^48);
	return a;
}

inline int Gcd(int a,int b){
	return b?Gcd(b,a%b):a;
}
bool usd[maxn];
inline bool Sieve(){
	for(int i=2;i<=1e6;i++)if(!usd[i]){
		int cnt=0;
		for(int j=1;i*j<=1e6;j++){
			int tmp=i*j;
			usd[tmp]=1,cnt+=c[tmp];
			if(cnt>1)return 0;
		}
	}
	return 1;
}

int main(){
	n=R_Int();
	int G;
	for(int i=1;i<=n;i++){
		c[a[i]=R_Int()]++;
		G=(i==1)?a[i]:Gcd(G,a[i]);
	}
	if(Sieve()){
		printf("pairwise coprime\n");
		return 0;
	}
	if(G==1)printf("setwise coprime\n");
	else printf("not coprime\n");
	return 0;
}
