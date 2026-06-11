#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll N,P;
ll table[10005];
char buf[200005];

int main(){

	scanf("%lld %lld",&N,&P);
	scanf("%s",buf);

	ll ans = 0;

	if(P == 2 || P == 5){

		for(ll i = 0; i < N; i++){
			if((buf[i]-'0')%P == 0){

				ans += (i+1);
			}
		}
		printf("%lld\n",ans);

		return 0;
	}

	for(int i = 0; i < P; i++){

		table[i] = 0;
	}

	table[0] = 1;
	ll num = 0;
	ll mult = 1;

	for(int i = N-1; i >= 0; i--){

		num = num+mult*(buf[i]-'0');
		num %= P;
		table[num]++;

		mult *= 10;
		mult %= P;
	}

	for(int i = 0; i < P; i++){

		ans += (table[i]*(table[i]-1))/2;
	}

	printf("%lld\n",ans);

	return 0;
}
