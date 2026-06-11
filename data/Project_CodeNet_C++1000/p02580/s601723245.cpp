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

using P = pair<ll, ll>;
int main(){
    ll h,w,m;
    cin >> h >> w >> m;
    ll h_cnt[h]; ll w_cnt[w];
    rep0(i, h-1) h_cnt[i] = 0; rep0(i, w-1) w_cnt[i] = 0;
    ll max_h = 0; ll max_w = 0;
    queue<P> bom;
    rep1(i, m){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        bom.push(P(x,y));
        h_cnt[x]++; w_cnt[y]++;
    }
    rep0(i, h-1) if(max_h < h_cnt[i]) max_h = h_cnt[i];
    rep0(i, w-1) if(max_w < w_cnt[i]) max_w = w_cnt[i];
    ll max_h_cnt = 0; ll max_w_cnt = 0;
    rep0(i, h-1) if(max_h == h_cnt[i]) max_h_cnt++;
    rep0(i, w-1) if(max_w == w_cnt[i]) max_w_cnt++;

    ll cnt_maxmaax = max_h_cnt*max_w_cnt;
    ll cnt_overlap = 0;
    if(cnt_maxmaax > m){
        cout << max_h + max_w << endl;
        return 0;
    }

    while(!bom.empty()){
        ll bomx = bom.front().first;
        ll bomy = bom.front().second;
        bom.pop();
        if(h_cnt[bomx] == max_h && w_cnt[bomy] == max_w){
            cnt_overlap++;
        }
    }

    if(cnt_overlap < cnt_maxmaax){
        cout << max_h + max_w << endl;
        return 0;
    }else{
        cout << max_h + max_w - 1 << endl;
        return 0;
    }
}