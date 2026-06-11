#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
long long modpow(long long x,long long n,long long mod){
    long long res = 1;
    while(n > 0) {
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return res;
}

long long modinv(long long x, long long mod){
    return modpow(x, mod - 2, mod); }
int main(){
ll m,n;
cin >> m >> n;
cout << modpow(m, n, MOD) << endl;
}
