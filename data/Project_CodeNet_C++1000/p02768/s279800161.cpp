#include<bits/stdc++.h>
using namespace std;
using lint = long int;
#define MOD 1000000007

lint N, a, b, res = 0;


lint binary_pow(lint a, lint n, lint m){
    lint res = 1;
    /*以降,nの2進数表記で考える...aもそれに合わせる*/
    while(n > 0){
        if(n & 1) res = (res * a) % m;  //奇数分は別
        a = (a * a) % m;
        n >>= 1; 
    }
    return res;
}

lint mod_inv(int x, int y){
    lint alpha = x, beta = y, u = 1, v = 0;
    lint d;
    while(beta){
        d = alpha / beta;
        alpha -= beta * d; swap(alpha, beta);
        u -= v * d; swap(u, v);
    }

    u %= y;
    if(u < 0) u += y;  //法を加えて正に
    return u;
}



lint mod_Comb(lint n, lint k, lint m){
    lint val = 1, inv = 1;
    for(int i = n-k+1; i <= n; i++){ val *= i; val %= m; }
    for(int i = 1; i <= k; i++){ inv *= i; inv %= m; }
    inv = mod_inv(inv, m);
    return (val * inv) % m;
}


int main(){
    cin >> N >> a >> b;
    res = (binary_pow(2,N,MOD)-mod_Comb(N,a,MOD)-mod_Comb(N,b,MOD)-1)%MOD;
    if(res < 0) res += MOD;
    cout << res << endl;
    return 0;
}

    