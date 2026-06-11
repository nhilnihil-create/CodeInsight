#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll d[10100];
int main(){
	ll k,q;
	scanf("%lld%lld",&k,&q);
	for(int i=1;i<=k;i++){
		scanf("%lld",&d[i]);
	}
	while(q--){
		ll n,x,m;
		scanf("%lld%lld%lld",&n,&x,&m);
		ll pre=0;
		for(int i=1;i<=k;i++){
			pre+=d[i]%m;
			if(d[i]%m==0) pre+=m;
		}
		ll tmp=(n-1)/k;
		ll ans=n-1;
		ll pt=tmp*pre;
		for(int i=1;i<=(n-1)%k;i++){
			pt+=d[i]%m;
			if(d[i]%m==0) pt+=m;
		}
		pt=(pt+x%m)/m;
		ans-=pt;
		printf("%lld\n",ans);
	}
	return 0;
}
