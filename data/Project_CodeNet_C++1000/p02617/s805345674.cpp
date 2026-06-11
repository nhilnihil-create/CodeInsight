#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll N;

int main(){

	scanf("%lld",&N);

	ll ans = 0;
	for(ll i = N; i >= 1; i--){

		ans += i*(N+1-i);
	}

	ll a,b;

	for(ll i = 0; i < N-1; i++){

		scanf("%lld %lld",&a,&b);

		if(a > b)swap(a,b);

		ans -= a*(N-b+1);
	}

	printf("%lld\n",ans);

	return 0;
}
