#include <iostream>
using namespace std;

long long MOD = 1e9 + 7;

long long modPow(long long x, long long a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    long long t = modPow(x, a / 2);
    return (t * t) % MOD;
}

long long modInv(long long x) {
    return modPow(x, MOD - 2);
}

long long modPerm(long long n, long long k) {
    long long ret = 1;
    for (long long i = 0; i < k; i++) {
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

int main(){
    long long x, y;
    cin >> x >> y;
    int ans = 0;
    if((x + y) % 3 == 0){
        //  m: (i+1, j+2) の移動回数, n: (i+2, j+1) の移動回数
        // m + n = (x + y) / 3
        // m - n = -x + y
        long long m = (-x + 2*y) / 3, n = (2*x - y) / 3;
        if(m >= 0 && n >= 0) {
            long long tmp = (modPerm(m, m) * modPerm(n, n)) % MOD;
            ans = (modPerm(m+n, m+n) * modInv(tmp)) % MOD;
        }
    }
    cout << ans;
    return 0;
}