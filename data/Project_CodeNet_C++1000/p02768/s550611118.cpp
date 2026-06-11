#include "bits/stdc++.h"

using namespace std;

int MOD = 1000000000 + 7;

long long modPow(int n, int num) {
    if (num == 0) return 1;
    long long res = modPow(n, num / 2);
    if (num % 2 == 0) res = (res * res) % MOD;
    else res = (((res * res) % MOD) * n) % MOD;
    return res;
}

long long modNck(int n, int k) {
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = (res * (n - i)%MOD * modPow(i + 1, MOD - 2)) % MOD;
    }
    return res;
}

int getMod(long long num) {
    long long res = num % MOD;
    if (res < 0)res += MOD;
    return res;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
    cout << getMod(modPow(2, n) - 1 - modNck(n, a) - modNck(n, b));
}