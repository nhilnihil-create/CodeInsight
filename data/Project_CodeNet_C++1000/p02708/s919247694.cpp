#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

ll N,K;
ll table[SIZE];

int main(){

	scanf("%lld %lld",&N,&K);

	N++;
	table[0] = 0;
	for(ll i = 1; i <= N; i++){

		table[i] = i;
		table[i] += table[i-1];
	}

	ll ans = 0;

	for(ll num = K; num <= N; num++){

		ll L = table[num];
		ll R = table[N]-table[N-num];

		ans += (R-L+1)%MOD;
		ans %= MOD;
	}

	printf("%lld\n",ans);

	return 0;
}
