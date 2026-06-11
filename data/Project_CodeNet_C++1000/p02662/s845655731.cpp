#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=2147483647;
const double pi=3.1415926535897932384626;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const ll mod=998244353;
const int maxn=3e3+5;
ll n,s,x,f[maxn];
int main(){
	n=read(),s=read();
	f[0]=1;
	for(int i=1;i<=n;i++){
		x=read();
		for(int j=s;j>=0;j--){
			if(f[j]){
				if(j+x<=s) f[j+x]=(f[j+x]+f[j])%mod;
				f[j]=f[j]*2%mod;
			}
		}
	}
	printf("%lld\n",f[s]);
	return 0;
}
