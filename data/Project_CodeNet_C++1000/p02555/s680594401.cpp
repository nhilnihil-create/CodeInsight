#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 2010;
const int M = 1000000007;

int n,m,gr;
ll ans,s;
ll dp[maxn][maxn]; // 分为 i 组 ， 和为 j 的方案数 
ll fac[maxn];

ll ksm(ll i, ll po){
	i %= M; 
	ll res = 1;
	while(po){
		if(po&1) res = res * i % M;
		po >>= 1;
		i = i * i % M;
	}
	return res;
}

ll inv(ll a){ return ksm(a,M-2); }

ll c(ll N, ll K){ 
	if(N<K)return 0;
    if(N<0||K<0)return 0;
	return 1ll*fac[N]*inv(fac[K])%M*inv(fac[N-K])%M; 
}

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	fac[0] = 1ll ;
	for(int i=1;i<=2001;i++) fac[i] = 1LL * fac[i-1] * i % M; 

	ans = 0;
	//printf("%lld\n",c(3,1));
	s = read();
	if(s<3) printf("0\n");
	else{
		gr = s / 3LL;
		
		for(int i=1;i<=gr;i++){
			m = s - 3ll * i;
//			printf("%lld\n",c(m+i-1ll,i-1ll));
			ans = (ans + c(m+i-1ll,i-1ll)) % M;
		} 
		printf("%d\n",(ans+M)%M);
	}

	return 0;
}