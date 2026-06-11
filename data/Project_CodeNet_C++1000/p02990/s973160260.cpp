#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

// 組み合わせを求める(グローバル汚さない版)
// 上の関数にまとめたバージョン
// nCk mod. p を出したくて、nが<1e7 かつ pが素数(1e9+7は素数)ならおk
// MAX 1e7で1400msぐらいかかるので注意(元版はそれの半分の時間で済む)
// 上と同じ2回目以降はキャッシュされるのでO(1)
// 第三引数は初回のみに使用する。 nCkのnの最大値を入れる(1e6+1推奨)。O(k)を使用する場合は不要
// else O(k) [nが固定されている必要はある]
// O(k)とO(n)の両方を選択することは出来ないのでそういったときはこの関数を命名分けて2個作る必要がある。
long long combination(int n, int k,int init_max_n = -1){
    static vector<ll> fac,finv,inv,big_n_tbl;
    static const int mod = 1e9+7;
    static bool big_n = false;
    static bool created = false;
    if (big_n) cerr << "big_n: trueのため、nは初期化時に使用した値になります" << endl;
    if (created && init_max_n != -1) cerr << "初期化済みのためinit_max_nの値は無視されます" << endl;
    if (!created) {
        if (init_max_n == -1) {
            cerr << "初期化に失敗しました。" << endl;
            exit(1);
        }
        if ( max(init_max_n,n) < 1e7+1) { // O(n) tbl
            fac.resize(init_max_n,0);
            finv.resize(init_max_n,0);
            inv.resize(init_max_n,0);
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < init_max_n; i++){
                fac[i] = fac[i - 1] * i % mod;
                inv[i] = mod - inv[mod%i] * (mod / i) % mod;
                finv[i] = finv[i - 1] * inv[i] % mod;
            }
        }
        else { // O(k) table (nは変更不可)
            chmin(k,n-k);
            big_n_tbl.resize(k+1,1);
            inv.resize(k+2,1);
            FOR(i,1,k+1){
                inv[i+1] = mod - inv[mod%(i+1)] * (mod/(i+1)) % mod;
                big_n_tbl[i] = (i == 1) ? n : ((n-i+1)*inv[i])%mod * big_n_tbl[i-1];
                if (i==1) cerr<< "i:1 " << big_n_tbl[i] << endl;
                big_n_tbl[i]%=mod;
            }
            big_n = true;
        }
        created = true;
    }
    if (big_n) return big_n_tbl[k];
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

void solve() {
    int N,K; cin >> N >> K;
    // initialize
    combination(N,K,1e7);
    FOR(i,1,K+1) cout << (combination(N-K+1,i) * combination(K-1,i-1))%ll(1e9+7) << endl;
}

int main() {
    solve();
    return 0;
}