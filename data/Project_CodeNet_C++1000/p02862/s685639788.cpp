#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAX = 1000000;
const int MOD = 1000000007;

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


ll X, Y;

int main(){
	cin >> X >> Y;
	
	ll n = (X+Y)/3;
	ll a = X - n;
	ll b = Y - n;
	
	ll result = 0;
	if ( 2*a+b != X || 2*b+a != Y || a < 0 || b < 0 ){
		result = 0;
	}
	else {
	    COMinit();
		result = COM(n,a);
	}
	
	cout << result  << endl;
	
	return 0;
}

