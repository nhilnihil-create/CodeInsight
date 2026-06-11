#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1000001;
const ll MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int x, y; scanf("%d %d", &x, &y);
	ll ans = 0;
	if((x + y) % 3 == 0){
		COMinit();
		int p = (2*x - y)/3;
		int q = (2*y - x)/3;
		ans = COM(p + q, p);
	}
	printf("%lld\n", ans);
}