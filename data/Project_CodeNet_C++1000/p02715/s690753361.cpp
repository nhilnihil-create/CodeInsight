#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll BigN = 1000000007;
ll powmod(ll a, ll n){
	ll ret = 1;
	for(ll i=0;i<60;i++){
		if(n&(1LL<<i)) ret*=a;
		a=(a*a)%BigN;
		ret%=BigN;
	}
	return ret;
}
int N,K;
int visit[100001]={1,1,};
ll dp[100001]={0,1,};
ll sol(int k, int r){
	if(r!=1) return sol(k/r,1);
	else if(visit[k]) return dp[k];
	ll ret = powmod(k,N);
	for(int i=2;i<=k;i++) ret=(ret+BigN-sol(k,i))%BigN;
	visit[k] = 1;
	return dp[k] = ret;
	
}
int main(int argc, char *argv[])
{
	scanf("%d %d",&N,&K);
	ll sum = 0;
	for(int i=1;i<=K;i++){
		sum += 1LL*i*sol(K,i);
		sum%= BigN;
	}
	printf("%lld",sum);
}