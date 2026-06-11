#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000001
#define INFL 1000000000000000001
ll s,x;
int main(void){
	scanf("%lld",&s);
	ll no=0,yes=1000000000;
	while(yes-no>1LL){
		ll med=(no+yes)/2LL;
		if(s<=med*med)yes=med;
		else no=med;
	}
	x=yes;
	if(x*x-s>x){
		printf("%lld %lld %lld %lld %lld %lld\n",0,0,x,1,x*x-s-x,x-1LL);
	}else{
		printf("%lld %lld %lld %lld %lld %lld\n",0,0,x,1,x*x-s,x);
	}
}
