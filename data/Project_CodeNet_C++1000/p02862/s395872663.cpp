#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 2010101;
ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i=2; i<MAX; i++) {
                fac[i] = fac[i - 1] * i % MOD;
                inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
        }
}

ll COM(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(int, char**) {
	COMinit();
	int x, y; cin >> x >> y;
	int diff = abs(x - y);
	int rem = min(x, y) - diff;
	if (rem<0 || rem%3!=0) {
		cout << 0 << endl;
		return 0;
	}
	ll ret = COM(diff + 2 * rem/3, rem/3);
	cout << ret << endl;
	return 0;
}
