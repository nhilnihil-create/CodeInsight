#include <stdio.h>
#include <string.h>
#define ll long long int
#define e 2.7182818
#define pi 3.14159
ll res = 0;
ll rest = 1;
ll oof = 1000000007;

ll pow (ll num, ll x){
	rest = 1;
	for (int i=0; i<num; i++){
		 rest *= x;
		 rest = rest % oof;
	}
	return rest;
}

int main (){
	ll num;
	scanf ("%lld", &num);
	res += (pow(num, 10));
	res -= (pow(num, 9));
	res -= (pow(num, 9));
	res += (pow(num, 8));
	res %= oof;
	res = (res+oof)%oof;
	printf ("%lld\n", res);
	
return 0;
}
