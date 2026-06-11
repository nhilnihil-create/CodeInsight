#include<bits/stdc++.h>
using namespace std;

int64_t pow_mod(int64_t a, int64_t b, int64_t c){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        int64_t t = pow_mod(a, b / 2, c);
        return t * t % c;
    }
    else return a * pow_mod(a, b - 1, c) % c;
}

int main(){
    int64_t n, a, b;
    cin >> n >> a >> b;
    int64_t mod = 1000000007;
    int64_t all, Xa = 1, Xb, Ya = 1, Yb;
    all = pow_mod(2, n, mod) - 1;
    for(int i=0; i<a; i++){
            Xa *= n - i;
            Xa %= mod;
    }
    Xb = Xa;
    for(int i=a; i<b; i++){
        Xb *= n - i;
        Xb %= mod;
    }
    for(int i=1; i<=a; i++){
        Ya *= i;
        Ya %= mod;
    }
    Yb = Ya;
    for(int i=a+1; i<=b; i++){
        Yb *= i;
        Yb %= mod;
    }
    Ya = pow_mod(Ya, mod - 2, mod);
    Yb = pow_mod(Yb, mod - 2, mod);
    
    cout << (all - Xa * Ya % mod - Xb * Yb % mod + mod * 2) % mod << endl; 

}