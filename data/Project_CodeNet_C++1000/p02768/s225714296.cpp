#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

const int P = 1000000007; //shuoud be prime

typedef unsigned long long LL;

LL Combination(LL n, LL r){
	if(n < 0 || r < 0 || r > n) return 0;

	if(n - r < r) r = n - r;
	if(r == 0) return (LL)1;
	if(r == 1) return (LL)n;

	LL *numerator   = (LL*)calloc(r, sizeof(LL));
	LL *denominator = (LL*)calloc(r, sizeof(LL));
	if(numerator == NULL || denominator == NULL) return 0;

	for(LL i=0; i<r; i++){
		numerator[i] = n - r + 1 + i;
		denominator[i] = i + 1;
	}

	for(LL p=2; p<=r; p++){
		LL pivot = denominator[p-1];
		if(pivot > 1){
			LL offset = (n - r) % p;
			for(LL k=p-1; k<r; k+=p){
				numerator[k - offset] /= pivot;
				denominator[k] /= pivot;
			}
		}
	}

	LL res = 1;
	for(LL i=0; i<r; i++){
		if(numerator[i]){
			res *= numerator[i];
			res = res % P;
		}
	}
	res = res % P;
	if(res < 0) res += P;
	return res;
}

long long n, a, b;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> a >> b;

	long long C = 100000;
	long long powC = 1;
	for(int i=1; i<=C; i++){
		powC = powC * 2;
		powC = powC % P;
	}
	long long q = n / C;
	long long r = n % C;
	// n = q*C + r
	long long ans = 1;
	for(int i=0; i<q; i++){
		ans = ans * powC;
		ans = ans % P;
	}
	for(int i=0; i<r; i++){
		ans = ans * 2;
		ans = ans % P;
	}
	ans -= 1;

	ans -= Combination(n, a);
	ans = ans % P;
	if(ans < 0) ans += P;

	ans -= Combination(n, b);
	ans = ans % P;
	if(ans < 0) ans += P;

	printf("%lld\n", ans);
	return 0;
}