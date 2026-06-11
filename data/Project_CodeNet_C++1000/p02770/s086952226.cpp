#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 5005

ll K,Q;
ll D[SIZE],work[SIZE];
ll COUNT[SIZE];


int main(){

	scanf("%lld %lld",&K,&Q);

	for(int i = 0; i < K; i++){

		scanf("%lld",&D[i]);
	}

	ll n,x,m;

	for(int loop = 0; loop < Q; loop++){

		scanf("%lld %lld %lld",&n,&x,&m);

		ll tmp = x%m;
		ll minus = 0;

		for(int i = 0; i < K; i++){

			work[i] = D[i]%m;

			COUNT[i] = (n-1)/K;
			if((n-1)%K >= i+1){

				COUNT[i]++;
			}

			tmp += work[i]*COUNT[i];

			if(work[i] == 0){

				minus += COUNT[i];
			}
		}

		printf("%lld\n",(n-1)-minus-tmp/m);
	}

	return 0;
}
