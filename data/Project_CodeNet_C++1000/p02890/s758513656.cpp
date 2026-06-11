#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 300005

ll N;
ll A[SIZE],SUM[SIZE];

int main(){

	scanf("%lld",&N);

	for(int i = 0; i < N; i++){

		A[i] = 0;
	}

	ll tmp;

	for(int i = 0; i < N; i++){

		scanf("%lld",&tmp);
		A[tmp-1]++;
	}
	sort(A,A+N);

	SUM[0] = 0;
	for(int i = 0; i < N; i++){

		SUM[i+1] = SUM[i]+A[i];
	}

	for(ll k = 1; k <= N; k++){
		ll left = 0,right = N/k+1,mid; //left:OK right:NG

		while(left+1 < right){
			mid = (left+right)/2; //仮の答え

			ll loc = lower_bound(A,A+N,mid)-A; //mid以上のものはmidにする(最大でもmidまでしか取れないため)
			ll sum = mid*(N-loc)+SUM[loc];

			if(sum >= mid*k){

				left = mid;

			}else{

				right = mid;
			}
		}
		printf("%lld\n",left);
	}

	return 0;
}
