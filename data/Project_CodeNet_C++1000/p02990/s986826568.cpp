#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
template <typename T> 
using lim = numeric_limits<T>;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MOD = 1e9+7;
const int N = 2005;
ll fact[N];
ll ifact[N];

ll perm(int n, int k){
    if (k > n) return 0;
    return fact[n]*ifact[n-k]%MOD;
}

ll combi(int n, int k){
    return perm(n,k)*ifact[k]%MOD;
}

ll modpow(ll b, ll e){
    ll ans = 1;
    while(e > 0){
        if (e&1) ans = ans*b%MOD;
        b = b*b%MOD;
        e >>= 1;
    }
    return ans;
}

ll modinv(ll x){
    return modpow(x, MOD-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = i*fact[i-1]%MOD;

    ifact[N-1] = modinv(fact[N-1]);
    for (int i = N-2; i >= 0; i--)
        ifact[i] = (i+1)*ifact[i+1]%MOD;

    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++){
        cout << combi(n-k+1, i)*combi(k-1,i-1)%MOD << "\n";
    }
}