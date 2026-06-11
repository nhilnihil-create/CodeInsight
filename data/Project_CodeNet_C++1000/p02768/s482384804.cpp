#include <bits/stdc++.h>
using namespace std;
using  LL = long long;

LL yhaa(LL x, LL n, LL mod){
    if (n == 0){
        return 1;
    }
    if (n%2 == 0){
        LL t = (yhaa(x,n/2, mod)) % mod;//偶数の時は半分
        return (t*t) % mod;
    }
    return (x * yhaa(x, n-1, mod)) % mod;
}

LL nCk(LL n,LL k,LL m){
    int K;
    if (2*k > n){
        K  = n - k;
    }
    else{
        K = k;
    }
    LL X = 1;
    for(int i = 0; i < K;i++){
        X = (X*(n-i)) % m;
    }
    LL Y = 1;
    for(int i = 1; i < K+1; i++){
        Y = (Y*i) % m;
    }
    LL YY = yhaa(Y,1000000005,m);
    return (X*YY) % m;

}


int main(){
    int n, a, b;
    cin >> n >> a >> b;
    long long int m = 1000000007;
    if (n == 2){
        cout << 0 <<endl;
    }
    else{
        LL all = yhaa(2,n,m);
        LL C_a = nCk(n,a,m);
        LL C_b = nCk(n,b,m);
        if((all - C_a - C_b - 1 ) % m > 0){
            cout << (all - C_a - C_b - 1 ) % m << endl;
        }
        else{
            cout << m + (all - C_a - C_b - 1 ) % m << endl;
        }
    }
    
}