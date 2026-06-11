#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


//combinationの最大値
#define MAX 200010
//mod
#define MOD 1000000007

//fac: 階乗、finv: 階乗の逆元(invの積)、inv: ある数の逆元(フェルマーの小定理より)
ll fac[MAX], finv[MAX], inv[MAX];

//テーブルを作る前処理
void combModInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算s
ll comb(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll pmod(ll n, ll m){
    if(m == 1) return n % MOD;
    if(m % 2 == 0){
        return pmod(n * n % MOD, m / 2) % MOD;
    }
    return n * pmod(n * n % MOD, (m - 1) / 2) % MOD;
}

// 二項係数計算(直接)
ll combDirect(ll n, ll k){
    ll frac = n; //分子
    ll deno = k; //分母
    for(ll i = n - 1; i > n - k; i--){
        frac = frac * i % MOD;
    }
    for(ll i = k - 1; i > 0; i--){
        deno = deno * i % MOD;
    }
    deno = pmod(deno, MOD - 2);
    return frac * deno % MOD;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans;
    ans = pmod(2, n) - 1;
    if(ans < 0){
        ans += MOD;
    }
    ans = ans - combDirect(n, a);
    if(ans < 0){
        ans += MOD;
    }
    ans = ans - combDirect(n, b);
    if(ans < 0){
        ans += MOD;
    }

    cout << ans << endl;

    return 0;
}
