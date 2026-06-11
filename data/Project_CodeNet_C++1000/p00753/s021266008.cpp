#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int is_prime[300000];
int prime[300000];

int main() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	int p = 0;
	for (int i = 2; i < 300000; i++) {
		if (is_prime[i]) {
			prime[p++] = i;
			for (int j = i * 2; j < 300000; j += i)is_prime[j] = false;
		}
	}
	int n;
	while (scanf("%d", &n), n) {
		printf("%d\n", upper_bound(prime, prime + p, 2 * n) - upper_bound(prime, prime + p, n));
	}
}