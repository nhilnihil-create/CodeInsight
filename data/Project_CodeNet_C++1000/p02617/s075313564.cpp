#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	scanf("%lld",&n);
	ll ans=n*(n+1)*(n+2)/6;
	for(ll i=1;i<n;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		if(u>v) swap(u,v);
		ans-=u*(n-v+1);
	}
	printf("%lld\n",ans);
}

