#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans * i % mod;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans * modinv(i, mod) % mod;
    }
    return ans;
}

int main() {
    ll X, Y;
    cin >> X >> Y;
    ll ans;
    if((X + Y) % 3 != 0){
        ans = 0;
    } else {
        ll A, B, N;
        
        A = (2 * Y - X) / 3;
        B = (2 * X - Y) / 3;
        if(A < 0 || B < 0){
            ans = 0;
        } else {
            N = A + B;
            ans = nCr(N, min(A, B));
        }
    }
    cout << ans << endl;
    return 0;
}
