#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)
const int MOD = 1e9+7;

int n, a[100000], cnt[3] = {};

int main(){
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", &a[i]);
	ll ans = 1;
	REP(i, 0, n){
		int pat = 0, pos = -1;
		REP(j, 0, 3) if(cnt[j]==a[i]) pat++, pos=j;
		if(pos>=0) cnt[pos]++;
		ans = ans * pat % MOD;
	}
	printf("%ld\n", ans);
	return 0;
}

