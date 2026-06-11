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
ll P[SIZE],loc[SIZE];
set<ll> SET;

int main(){

	ll L[2],R[2],left[2],right[2];

	scanf("%lld",&N);

	for(int i = 0; i < N; i++){

		scanf("%lld",&P[i]);
		P[i]--;
		loc[P[i]] = i;
	}

	ll ans = 0;

	for(ll i = N-1; i >= 0; i--){

		ll tmp = loc[i];
		SET.insert(tmp);

		for(int k = 0; k < 2; k++){

			L[k] = -1;
			R[k] = N;
		}

		auto it = SET.find(tmp);

		for(int k = 0; k < 2; k++){
			if(it == SET.begin())break;

			it--;
			L[k] = *it;
		}

		it = SET.find(tmp);

		for(int k = 0; k < 2; k++){
			it++;
			if(it == SET.end())break;

			R[k] = *it;
		}

		left[0] = tmp-L[0],left[1] = L[0]-L[1];
		right[0] = R[0]-tmp,right[1] = R[1]-R[0];

		ans += (i+1)*(right[1]*left[0]+right[0]*left[1]);
	}

	printf("%lld\n",ans);

	return 0;
}
