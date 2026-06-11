#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
ll ans[2000050];
void solve(int T){
	ll n,fin;
	int siz=0;
	scanf("%lld",&n);
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ans[++siz]=i;
	}
	fin=ans[siz]+n/ans[siz]-2;
	printf("%lld",fin);
}
signed main(){
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve(i);
	}
}