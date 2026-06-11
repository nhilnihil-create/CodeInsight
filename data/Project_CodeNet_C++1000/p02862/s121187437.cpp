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

const int MAX = 3000000;
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

// 二項係数計算
long long COMB(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % P) % P;
}

long long X, Y;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	COMBinit();

	cin >> X >> Y;
	long long K = X + Y;
	if((K % 3) != 0){
		printf("0\n");
		return 0;
	}
	int k = K / 3;
	if(2*Y < X || Y > 2*X){
		printf("0\n");
		return 0;
	}

	long long ans = COMB(k, ((2 * K) / 3) - X);
	ans %= P;
	if(ans < 0) ans += P;
	printf("%lld\n", ans);
	return 0;
}