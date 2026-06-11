#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N,K;
ll table[SIZE];

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}


int main(){

	scanf("%lld %lld",&N,&K);


	ll ans = 0;

	for(ll num = K; num >= 1; num--){

		ll tmp= mod_pow(K/num,N,MOD); //N個全てがnumの倍数

		for(ll i = 2; num*i <= K; i++){ //自分の倍数が最小公倍数である場合を除く

			tmp -= table[num*i];
			if(tmp < 0){
				tmp += MOD;
			}
		}

		ans += num*tmp;
		ans %= MOD;
		table[num] = tmp;
	}

	printf("%lld\n",ans);

	return 0;
}
