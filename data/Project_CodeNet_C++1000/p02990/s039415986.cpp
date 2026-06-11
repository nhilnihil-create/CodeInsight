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

const int MAX = 50000;
const int P = 1000000007; //shuoud be prime

long long fac[MAX], finv[MAX], inv[MAX];

void COMBinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % P;
        inv[i] = P - inv[P%i] * (P / i) % P;
        finv[i] = finv[i - 1] * inv[i] % P;
    }
}

long long COMB(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % P) % P;
}

long long N, K;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> K ;
	COMBinit();

	printf("%lld\n", N-K+1);
	for(int i=2; i<=K; i++){
		long long a, b;
		b = COMB(K-1, i-1);
		a = 0;
		for(int j=i-1; j <= N-K; j++){
			a += COMB(j-1, i-2)*(N-K-j+1);
			a %= P;
		}
		printf("%lld\n", (a*b)%P);
	}
	return 0;
}