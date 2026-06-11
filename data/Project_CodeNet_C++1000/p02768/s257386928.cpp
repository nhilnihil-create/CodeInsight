#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

ll const MAX = 510000;
ll const MOD = 1000000007;

// 二分累乗法 O(logn)
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<ll> fact_inv, inv, Com;

/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(ll n) {
    fact_inv.resize(MAX + 5);
    inv.resize(MAX + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < MAX + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }

    Com.resize(MAX + 5);
    Com[0] = 1;

    for (int i = 1; i < MAX + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int k) { return Com[k]; }

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    init_nCk(n);

    ll ans = modpow(2, n, MOD) - 1;
    ll ac = nCk(a) % MOD;
    ll bc = nCk(b) % MOD;

    cout << ((ans - ac - bc) + 10 * MOD) % MOD << endl;

    return 0;
}