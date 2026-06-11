#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#include <sstream>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using ss = stringstream;

const ll mod = 1000000000 + 7; //10^9
const ll llmax = pow(10, 18);



struct factorial
{
    vector<ll> fac, finv, inv;

    factorial(int n) : fac(2, 1), finv(2, 1), inv(2, 1)
    {
        int i;

        rep(i, 2, n + 1)
        {
            fac.push_back(fac[i - 1] * i % mod);
            inv.push_back(mod - inv[mod % i] * (mod / i) % mod);
            finv.push_back(finv[i - 1] * inv[i] % mod);
        }
    }

    ll comb(int n, int k)
    {
        if (n < k)
        {
            return 0;
        }

        if (n < 0 || k < 0)
        {
            return 0;
        }

        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }

    ll perm(int n, int k)
    {
        if (n < k)
        {
            return 0;
        }

        if (n < 0 || k < 0)
        {
            return 0;
        }

        return fac[n] * finv[n - k] % mod;
    }
};
ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

ll mod_conb(ll n, ll k)
{
    ll ans = 1;

    if (n < k || n < 0 || k < 0)
    {
        return 0;
    }

    for (long long i = 0; i < k; i++)
    {
        ans *= n - i;
        ans %= mod;
        ans *= power(i + 1, mod - 2);
        ans %= mod;
    }

    return ans;
}
// bool is_integer(double x){
//     return floor(x) == x;
// }





/*逆元　あまりの割り算をするときにこいつをかける(a/b→a*modinv(b))*/
// mod. m での a の逆元 a^{-1} を計算する
// ll modinv(ll a,ll m){
//     long long b = m, u = 1, v = 0;
//     while (b) {
//         long long t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= m;
//     if (u < 0) u += m;
//     return u;
// }



// bool IsPrime(ll num)
// {
//     if (num < 2) return false;
//     else if (num == 2) return true;
//     else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
 
//     double sqrtNum = sqrt(num);
//     for (int i = 3; i <= sqrtNum; i += 2)
//     {
//         if (num % i == 0)
//         {
            // 素数ではない
//             return false;
//         }
//     }
 
    // 素数である
//     return true;
// }
 
 /*階乗*/
// ll facctorialMethod(ll k){
//     ll sum = 1;
//     for (ll i = 1; i <= k; ++i)
//     {
//         sum *= i;
        //sum%=mod;//あまりを出力せよ問題の時はこれもやる
//     }
//     return sum;
// }


ll combination(int a, int b){
    if(a < b){
        return 0;
    }
    if(a < 0 || b < 0){
        return 0;
    }
    if(a == b || b == 0){
        return 1;
    }
    return (combination(a - 1, b - 1) % mod + combination(a - 1, b) % mod) % mod;
}

int main() {
    int S;
    cin >> S;
    int a = 1;
    ll ans = 0;
    while(S / a >= 3){
        int b = S - 3 * a;
        ans += mod_conb(b + a - 1, a - 1);
        ans %= mod;
        a ++;
    }
    cout << ans << endl;
}
