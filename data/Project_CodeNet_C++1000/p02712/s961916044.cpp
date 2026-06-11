#include<stdio.h>
#include<string.h>

typedef long long ll;

int main(){
	ll n = 0;
	ll x = 0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		if(i%3==0&&i%5==0){
		}
		else if(i%3==0){
		}
		else if(i%5==0){
		}
		else
			x+=i;
	}
	printf("%lld",x);
}