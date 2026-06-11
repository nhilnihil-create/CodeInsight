#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005

ll N;
ll A[SIZE],TOP[SIZE];
ll POW[61];

int main(){

	POW[0] = 1;
	for(int i = 1; i <= 60; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%lld",&N);

	ll all = 0;

	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		all ^= A[i];
	}

	ll ans = all;

	for(int i = 0; i < N; i++){

		A[i] &= ~all;
	}

	for(int i = 0; i <= 60; i++){

		TOP[i] = -1;
	}

	ll r = 0;

	for(int i = 60; i >= 0; i--){

		//r行目以降で、i桁目に1が立っている行を探す
		ll loc = r;
		for(;loc < N; loc++){
			if(A[loc] & POW[i]){

				swap(A[loc],A[r]);
				break;
			}
		}
		if(loc == N)continue; //1が立っている行なし

		TOP[r] = i; //確定r行目の、1が立っている桁はi

		for(int k = 0; k < N; k++){
			if(k == r)continue;
			if(A[k] & POW[i]){

				A[k] ^= A[r];
			}
		}
		r++;
	}

	ll X = 0;

	for(int i = 60; i >= 0; i--){

		ll work = X|POW[i];

		ll tmp = work;
		for(int k = 0; k < r; k++){
			if(tmp & POW[TOP[k]]){

				tmp ^= A[k];
			}
		}
		if((tmp & work) == 0){

			X = work;
		}
	}

	ans += 2*X;

	printf("%lld\n",ans);

	return 0;
}


