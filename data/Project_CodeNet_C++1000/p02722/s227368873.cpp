#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	ll N;
	scanf("%lld",&N);


	vector<ll> V;
	V.push_back(N);
	if(N > 2){
		V.push_back(N-1);
	}


	for(ll i = 2; i*i <= N; i++){

		if(N%i == 0){

			ll tmp = N;
			while(tmp%i == 0){

				tmp /= i;
			}

			if(tmp%i == 1){

				V.push_back(i);
			}

			ll a = N/i;

			tmp = N;
			while(tmp%a == 0){

				tmp /= a;
			}
			if(tmp%a == 1){

				V.push_back(a);
			}

		}else if((N-1)%i == 0){

			V.push_back(i);
			V.push_back((N-1)/i);
		}
	}

	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());

	printf("%lld\n",V.size());

	return 0;
}
