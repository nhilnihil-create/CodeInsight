/*
   وَعَلَى اللَّهِ فَلْيَتَوَكَّلِ الْمُؤْمِنُونَ
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7 ;

ll binpow(ll a, ll b){
   ll res = 1 ;
   while(b > 0){
       if(b & 1) res = (res % mod) * (a % mod), res %= mod ;
       a = (a % mod) * (a % mod) ;
       a %= mod ;
       b >>= 1 ;
   }
   return res ;
}

ll divide(ll a, int b){
    return ((a % mod) * binpow(b, mod - 2) % mod) % mod;
}

ll nCr(ll n, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res = ((res % mod) * ((n - i) % mod)) % mod;
        res = divide(res, i + 1);
    }

    return res;
}

int main()
{
   //  freopen("in.txt", "r", stdin) ;
   ios :: sync_with_stdio(0) ;
   cin.tie(0) ;
   cout.tie(0) ;

   ll n, a, b ;
   cin >> n >> a >> b ;
   ll tot = binpow(2, n) ;
   ll f = nCr(n, a) ;
   ll s = nCr(n, b) ;
   ll ans = ((f % mod)  + (s % mod)) % mod ;
   ans = ((ans % mod) + 1) % mod ;
   ll fin = ((tot - ans) % mod + mod) % mod ;
   cout << fin;
}
//
//994457068
//34076506
