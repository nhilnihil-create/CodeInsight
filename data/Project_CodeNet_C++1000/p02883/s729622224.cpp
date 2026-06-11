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
ll A[SIZE];
ll F[SIZE];

int main(){

	scanf("%lld %lld",&N,&K);

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}
	for(int i = 0; i < N; i++){

		scanf("%lld",&F[i]);
	}

	if(N == 1){

		printf("%lld\n",F[0]*max(0LL,A[0]-K));
		return 0;
	}

	sort(A,A+N);
	sort(F,F+N);

	ll left = 0,right = HUGE_NUM,mid = (left+right)/2;
	ll ans = HUGE_NUM;

	while(left <= right){

		ll tmp = 0;

		for(int i = 0; i < N; i++){

			ll a = A[i];
			ll f = F[N-1-i];

			if(a*f <= mid)continue;

			tmp += a-mid/f;
		}

		if(tmp <= K){

			ans = mid;
			right = mid-1;

		}else{

			left = mid+1;
		}
		mid = (left+right)/2;
	}

	printf("%lld\n",ans);

	return 0;
}
