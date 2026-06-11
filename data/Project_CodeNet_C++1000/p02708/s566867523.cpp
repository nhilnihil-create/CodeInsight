#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;
long factorials[500001];

int pre_factorials(int n){

    factorials[0] = 1;

    for (int i = 0; i < n; i++) {
        factorials[i + 1] = (long)(i + 1) * factorials[i] % mod;
    }
    
    return 0;
}

long modpow(long a, long p){
    
    if (p == 0) return 1;
    
    if (p % 2 == 0) {
        return modpow(a * a % mod, p / 2);
    
    } else
        return a * modpow(a, p - 1) % mod;
}

long comb(long a, long b){

    long af = factorials[(int) a];
    long bf = factorials[(int) b];
    long abf = factorials[(int) (a - b)];
    long res = af * modpow(bf, mod - 2) % mod * modpow(abf, mod - 2) % mod;
    return res;
}

int main(){
    
    long N = 200010;
    pre_factorials(N);
    
    long n, k;
    cin >> n >> k;
    n++;
    
    long ans = 0, min, max;
    
    for(long i = k; i <= n; i++){
        min = (1 + i) * i / 2;
        max = (n + n - i + 1) * i / 2;
        ans += max - min + 1;
        ans %= mod;
    }
    
    cout << ans << "\n";
    
    return 0;
}


