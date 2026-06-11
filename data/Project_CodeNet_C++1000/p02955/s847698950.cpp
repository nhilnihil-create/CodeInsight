#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 505

ll N,K;
ll A[SIZE],work[SIZE];
set<ll> SET;

int main(){

	scanf("%lld %lld",&N,&K);

	ll sum = 0;

	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		sum += A[i];
	}

	for(ll i = 1; i*i <= sum; i++){
		if(sum%i == 0){
			SET.insert(i);
			SET.insert(sum/i);
		}
	}

	ll ans = 1;

	for(ll x: SET){

		for(ll i = 0; i < N; i++){

			work[i] = A[i]%x;
		}
		sort(work,work+N);

		ll plus = 0;

		for(ll i = 0; i < N; i++){

			plus += x-work[i];
		}

		ll need = plus;
		ll minus = 0;

		for(ll i = 0; i < N; i++){
			minus += work[i];
			plus -= (x-work[i]);
			need = min(need,max(minus,plus));
		}
		if(need <= K){

			ans = max(ans,x);
		}
	}

	printf("%lld\n",ans);

	return 0;
}
