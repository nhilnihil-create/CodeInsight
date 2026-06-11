#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 510000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow( ll x, ll y ){
	ll result = 1;
	ll xx = x % MOD;
	while ( y ){
		if ( y & 1 )
			result = result * xx % MOD;
		xx = xx * xx % MOD;
		y >>= 1;
	}
	return result;
}

ll ncr2( ll n, ll r ){
	ll result = 1;
	for ( ll i = 0; i < r; i++ ){
		result = ((result * (n-i) % MOD) * inv[r-i])%MOD;
	}
	return result;
}

int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	
    COMinit();
	cout << (modpow(2,n)-1 - ncr2(n,a) - ncr2(n,b) + MOD*3)%MOD << endl;
	
	
	
	
	return 0;
}

