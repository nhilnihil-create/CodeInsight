#include <iostream>
#include <vector>
using namespace std;typedef long long int mint_type;
const mint_type MOD = 1000000007;
const mint_type MAX = 1000000;
class mint{
    public:
        static mint_type fac[MAX];
        static mint_type finv[MAX];
        static inline mint_type mod(mint_type a, mint_type mod = MOD){ return (a % mod + mod) % mod;}
        static mint_type mpow(mint_type a, mint_type n, mint_type mod = MOD);
        static mint_type extGCD(mint_type a, mint_type b, mint_type& x, mint_type& y);
        static mint_type minv(mint_type a, mint_type mod = MOD);
        static void mcinit(mint_type max = MAX, mint_type mod = MOD);
        static mint_type mchoose(mint_type n, mint_type r, mint_type mod = MOD);
};
mint_type mint::fac[MAX];
mint_type mint::finv[MAX];

mint_type mint::mpow(mint_type a, mint_type n, mint_type mod){
    mint_type result = 1;
    while(n > 0){
        if(n & 1){
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    
    return result;
}

mint_type mint::extGCD(mint_type a, mint_type b, mint_type& x, mint_type& y){
    if(a % b == 0){
        x = 0;
        y = 1;
        return b;
    }
    
    mint_type d = extGCD(b, a % b, x, y);
    mint_type tmp = -y * (a / b) + x;//
    x = y;
    y = tmp;
    return d;
}

mint_type mint::minv(mint_type a, mint_type mod){
    mint_type x, y;
    mint::extGCD(a, mod, x, y);
    //while(x < 0) x += mod;
    return mint::mod(x);
}

void mint::mcinit(mint_type max, mint_type mod){
    mint::fac[0] = 1;
    for(mint_type i = 1; i < max; i++){
        mint::fac[i] = mint::fac[i-1] * i % mod;
    }
    mint::finv[max-1] = mint::minv(fac[max-1]);
    for(mint_type i = max-1; i > 0; i--){
        mint::finv[i-1] = mint::mod(mint::finv[i] * i);
    }
}

mint_type mint::mchoose(mint_type n, mint_type r, mint_type mod){
    return mint::mod(mint::fac[n] * mint::mod(mint::finv[r] * mint::finv[n-r]));
}

int main(){
    int x, y;
    cin >> x >> y;
    long long int ans = 0;
    if((x+y)%3 == 0){
        int k = (x+y)/3;
        if(k <= x && x <= 2*k && k <= y && y <= 2*k){
            mint::mcinit();
            ans = mint::mchoose((long long int)k, (long long int)(x-k));
        }
    }
    cout << ans << endl;
}