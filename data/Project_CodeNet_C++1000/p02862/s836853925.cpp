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

/*コンビネーションの高速化
フェルマーの小定理と逆元の利用*/
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

    y = modpow(y, mod-2);//フェルマーの小定理と逆元を使うことで、計算できない割り算を掛け算にして計算可能にする
    //yで割りたい時はy^(mod-2)を掛ければ良い
    return x*y%mod;//計算可能
}

int main(){
    long long x, y;
    cin >> x >> y;

    if((-x + 2 * y) % 3 != 0 || (2*x - y) % 3 != 0){
        printf("0\n");
        return 0;
    }

    long long a = (-x + 2 * y)/3;
    long long b = (2 * x - y)/3;

    if(a < 0 || b < 0){
        printf("0\n");
        return 0;
    }

    long long ans = comb(a+b, a);

    cout << ans << endl;
    return 0;
}