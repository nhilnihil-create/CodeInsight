#include <stdio.h>
#include <string.h>
#define ll long long int
#define e 2.7182818
#define pi 3.14159

int main (){
	ll num, res;
	scanf ("%lld", &num);
	for (ll i=1; i<num; i++){
		res += (num-1)/i;
	}
	printf ("%lld", res);

return 0;
}
