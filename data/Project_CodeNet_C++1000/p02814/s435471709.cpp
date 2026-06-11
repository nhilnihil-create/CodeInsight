#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll N,M;
ll A[100005];

//最大公約数
ll gcd(ll x,ll y){

	x = abs(x);
	y = abs(y);

	if(x < y){
		swap(x,y);
	}
	if(y == 0){
		return x;
	}else{
		return gcd(y,x%y);
	}
}

//最小公倍数
ll lcm(ll x,ll y){

	return (x*y)/gcd(x,y);
}

int main(){

	scanf("%lld %lld",&N,&M);

	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		A[i] /= 2;
	}


	int count = 0;

	while(A[0]%2 == 0){

		A[0] /= 2;
		count++;
	}

	for(int i = 1; i < N; i++){

		int tmp = 0;

		while(A[i]%2 == 0){
			A[i] /= 2;
			tmp++;
		}

		if(tmp != count){

			printf("0\n");
			return 0;
		}
	}

	for(int i = 0; i < count; i++){

		M /= 2;
	}

	ll LCM = 1;
	for(int i = 0; i < N; i++){

		LCM = lcm(A[i],LCM);
	}

	ll ans = (M/LCM+1)/2;

	printf("%lld\n",ans);

	return 0;
}
