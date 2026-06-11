#include <iostream>
#include <utility>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);++i)


const int MOD = 1e9 + 7;
const int MAX=10000000;
long long fac[MAX], finv[MAX], inv[MAX];



long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


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


int main(){

    ll X,Y;
    scanf("%lld %lld",&X,&Y);

 
    int a,b;
    bool flag=true;

    b=(2*X-Y)/3;
    a=X-2*b;

    if((2*X-Y)%3==0&&b>=0&&a>=0){
        b=(2*X-Y)/3;
        
        a=X-2*b;

        //cout<<"a:"<<a<<" b:"<<b<<endl;
    }else{
        flag=false;
    }

    COMinit();

    if(flag){
        cout<<COM(a+b,a)%MOD<<endl;
    }else{
        cout<<0<<endl;
    }



}