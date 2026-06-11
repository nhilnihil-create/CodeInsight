#include <bits/stdc++.h>

using namespace std;

int N, A, B;
long long MOD = 1000000007;

long long modmult(long long a, long long b){
    return (a * b) % MOD;
}

long long modminus(long long a, long long b){
    if(a-b < 0){
        return a - b + MOD;
    } else {
        return a - b;
    }
}

long long modadd(long long a, long long b){
    return (a + b) % MOD;
}

long long fastpowmod(long long _x, long long _n)
{
	long long ret = 1;
	while(0 < _n)
	{
		if((_n % 2) == 0)
		{
			_x *= _x;
            _x %= MOD;
			_n >>= 1;
		}
		else
		{
			ret *= _x;
            ret %= MOD;
			--_n;
		}
	}
	return ret;
}

long long factmod[2*100000 + 1] = {0};
void factmod_init(){
    factmod[0] = 1;
    factmod[1] = 1;
    for(int i = 2; i <= 2 * 100000; i++){
        factmod[i] = modmult(factmod[i-1], i);
    }
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

long long factmod2(long long n){
    long long ret = 1;
    for(long long i = 1; i <= n; i++){
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

long long complx(long long n, long long r){
    return modmult(modmult(factmod[n], modinv(factmod[r], MOD)), modinv(factmod[n-r], MOD));
}

long long nprmod(long long n, long long r){
    long long ret = 1;
    for(long long i = 0; i < r; i++){
        ret *= n - i;
        ret %= MOD;
    }
    return ret;
}

long long complx2(long long n, long long r){
    return modmult(nprmod(n, r), modinv(factmod[r], MOD));
}

int main(){
    factmod_init();
    cin >> N >> A >> B;
    cin.ignore();

    if(N <= 0) return 0;

    long long ans = fastpowmod(2, N);
    ans = modminus(ans, 1); // 1つもない場合を除く
    long long a_cmp = complx2(N, A);
    long long b_cmp = complx2(N, B);
    ans = modminus(modminus(ans, a_cmp), b_cmp);
    cout << ans << endl;
    return 0;
}