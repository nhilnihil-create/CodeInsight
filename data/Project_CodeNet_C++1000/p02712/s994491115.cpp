#include <stdio.h>
#include <string.h>
#define ll long long

ll t;
ll n;

int main() {
	scanf("%d", &t);
	ll total = 0;

	for(ll i = 1; i <= t; i++) {
		if(i % 3 != 0 && i % 5 != 0) {
			total += i;
		}
	}

	printf("%lld\n", total);
	return 0;
}