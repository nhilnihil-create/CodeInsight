#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 2000005


ll fact[SIZE],inv_fact[SIZE];

ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0){
		d = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else{
		x = 1;
		y = 0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}

ll nCk(ll n,ll k){

	ll ret = fact[n]*inv_fact[k];
	ret %= MOD;
	ret *= inv_fact[n-k];

	return ret%MOD;
}



int main(){

	fact[0] = 1;
	for(ll i = 1; i < SIZE; i++){
		fact[i] = i*fact[i-1];
		fact[i] %= MOD;
	}
	inv_fact[SIZE-1] = mod_inverse(fact[SIZE-1],MOD);
	for(ll i = SIZE-1; i >= 1; i--){

		inv_fact[i-1] = inv_fact[i]*i;
		inv_fact[i-1] %= MOD;
	}

	ll X,Y;
	scanf("%lld %lld",&X,&Y);

	if((X+Y)%3 != 0){

		printf("0\n");
		return 0;
	}

	if(2*X-Y >= 0 && (2*X-Y)%3 == 0 && (X+Y)/3 >= (2*X-Y)/3){

		printf("%lld\n",nCk((X+Y)/3,(2*X-Y)/3));
		return 0;
	}
	if(2*Y-X >= 0 && (2*Y-X)%3 == 0 && (X+Y)/3 >= (2*Y-X)/3){

		printf("%lld\n",nCk((X+Y)/3,(2*Y-X)/3));
		return 0;
	}

	printf("0\n");

	return 0;
}
