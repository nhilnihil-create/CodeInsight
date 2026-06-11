#include <iostream>
#include <cstdio>
using namespace std;

long long mod = 1e9 + 7;

long long modpow(long long x, long long n) {
    x = x%mod;
    if(n == 0){
        return 1;
    }
    else if(n%2 == 1){
        return(x*modpow(x, n-1))%mod;
    }
    else{
        return modpow((x*x)%mod, n/2)%mod;
    }
}

long long comb(long long n, long long k){
    long long x = 1;

    for(long long i = n-k+1; i <= n; i++){
        x = x*i;
        x = x%mod;
    }
    long long y = 1;
    for(long long i = 1; i <= k; i++){
        y = y*i;
        y = y%mod;
    }

    y = modpow(y, mod-2);

    return x*y%mod;
}

int main(){
    long long n, k;
    cin >> n >> k;

    for(long long i = 1; i <= k; i++){
        long long blue = comb(k - 1, i - 1);
        long long red = comb(n - k + 1, i);
        printf("%lld\n", blue*red%mod);
    }
    return 0;
}