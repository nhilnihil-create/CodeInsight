#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    rep0(i, N-1) cin >> P[i], --P[i];
    rep0(i, N-1) cin >> C[i];
    ll INF = 1e18;
    ll ans = -INF;
    rep0(i, N-1) {
        int v = i;
        ll cycle_sum = 0;
        int cycle_cnt = 0;
        while (true) {
            cycle_cnt++;
            cycle_sum += C[v];
            v = P[v];
            if (v == i) break;
        }
        ll path = 0;
        int cnt = 0;
        while (true) {
            cnt++;
            path += C[v];
            if (cnt > K) break;
            int num = (K - cnt) / cycle_cnt;
            ll score = path + max(0ll, cycle_sum) * num;
            if (ans < score) ans = score;
            v = P[v];
            if (v == i) break;
        }
    }
    cout << ans << endl;
    return 0;
}