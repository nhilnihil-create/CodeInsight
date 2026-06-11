#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;
#define mod 1000000007
u64 modinv(u64 a, u64 m) {
    u64 b = m, u = 1, v = 0;
    while (b) {
        u64 t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
u64 F[1000007], FInv[1000007];

void generate(){
    FInv[0] = F[0] = 1;
    
    for (int i = 1; i < 1000007; i++) {
        F[i] = (F[i - 1]*i) % mod;
        FInv[i] = (FInv[i - 1] * modinv(i, mod)) % mod;
    }
}

int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    u64 X, Y;
    cin >> X >> Y;
    u64 W, H;
    W = 2* X - Y, H = 2*Y - X;
    if (W < 0 || H < 0 || W % 3 || H % 3) {
        cout << 0 << endl;
        return 0;
    }
    generate();
    u64 ans = 1;
    W /= 3, H /= 3;
    ans = (ans * F[W+H]) % mod;
    ans = (ans * FInv[W]) % mod;
    ans = (ans * FInv[H]) % mod;
    cout << ans << endl;
    
    return 0;
    
}
