//
// Created by Hideaki Imamura on 2020-03-27.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
const ll mod = 1000000007;

inline ll take_mod(ll a) {
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b) {
    return take_mod(a + b);
}

inline ll sub(ll a, ll b) {
    return take_mod(a - b);
}

inline ll mul(ll a, ll b) {
    return take_mod(a * b);
}

inline ll mod_pow(ll x, ll n) {
    ll res = 1LL;
    while (n > 0) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x) {
    return mod_pow(x, mod - 2);
}

string L;

int main() {
    cin >> L;

    ll num = 0;
    ll res = 0;
    for (int i = 0; i < L.size(); ++i) {
        int len = (int)L.size() - i - 1;
        if (L[i] == '1') {
            res = add(res, mul(mod_pow(2, num), mod_pow(3, len)));
            num++;
        }
    }
    res = add(res, mod_pow(2, num));
    cout << res << endl;
    return 0;
}