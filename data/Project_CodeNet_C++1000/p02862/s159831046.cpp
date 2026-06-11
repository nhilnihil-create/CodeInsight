#include<iostream>

static const long long MOD = 1e9+7;

long long inv(long x, long n){
    if(n == 1) return x;
    long long cur = inv(x, n / 2);
    cur = cur * cur % MOD;
    if(n % 2 == 0){
        return cur;
    }else{
        return cur * x % MOD;
    }
}

long long combination(long long n, long long k){
    long long upper = 1;
    long long bellow = 1;
    for(long long i = n - k + 1; i <= n; i++){
        long long temp = upper;
        upper *= i;
        upper %= MOD;
    }
    for(long long i = 1; i <= k; i++){
        bellow *= inv(i, MOD-2);
        bellow %= MOD;
        // std::cout << bellow << std::endl;
    }
    return (upper * bellow) % MOD ;
}

int main(void){
    // int n = 5;
    // int x = 2;
    // combination(n, x);
    //  std::cout << combination(n, x) << std::endl;
    long long x, y, k, m;
    std::cin >> x >> y;
    k = (- x + 2 * y) / 3;
    m = (2 * x - y) / 3;
    if(k + 2 * m == x && 2 * k + m == y && k >= 0 && m >= 0){
        std::cout << combination(k+m, k) << std::endl;
    }else{
        std::cout << 0 << std::endl;
    }

    return 0;
}